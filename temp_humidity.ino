#include <DHT.h>
#include "config.h"

AdafruitIO_Feed * TEMP=io.feed("temp");
AdafruitIO_Feed * HUMIDITY =io.feed("humidity");

DHT dht(D2,DHT11);

void setup() {
Serial.begin(115200);
dht.begin();
io.connect();

while(io.status() < AIO_CONNECTED){
  Serial.println(".");
  delay(500);
}

Serial.println(io.statusText());
/////
}

void loop() {
io.run();

float t=dht.readTemperature();
float h= dht.readHumidity();

TEMP->save(t);  // ersale data az nodemcu be adafruit
HUMIDITY->save(h);
Serial.print("temp= ");
Serial.println(t);
Serial.print("humidity= ");
Serial.println(h);
delay(4000);
}

