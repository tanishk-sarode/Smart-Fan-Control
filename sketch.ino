#include "DHT.h"

#define DHT_INDOOR_PIN 2
#define DHT_INDOOR_TYPE DHT22
#define DHT_OUTDOOR_PIN 3
#define DHT_OUTDOOR_TYPE DHT22
#define REL_PIN 10

DHT dht_indoor(DHT_INDOOR_PIN, DHT_INDOOR_TYPE);
DHT dht_outdoor(DHT_OUTDOOR_PIN, DHT_OUTDOOR_TYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("FAN test!"));

  pinMode(REL_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  dht_indoor.begin();
  dht_outdoor.begin();
}

void loop() {
  delay(2000);

  float h_in = dht_indoor.readHumidity();
  float t_in = dht_indoor.readTemperature();
  float t_out = dht_outdoor.readTemperature();

  Serial.print(F("Humidity IN: "));
  Serial.print(h_in);
  Serial.print(F("%  Temperature IN: "));
  Serial.print(t_in);
  Serial.print(F("\u00b0C Temperature OUT: "));
  Serial.print(t_out);
  Serial.println(F("\u00b0C"));

  if (t_in <= t_out) {
    digitalWrite(REL_PIN, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(REL_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
