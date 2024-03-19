#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(3);

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, change Adafruit_SSD1306.h");
#endif

void setup()   {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.display();
  delay(12500);

  display.clearDisplay();
  display.display();
}


void loop() {
  long runtime = millis() / 1000;
  long seconds = runtime % 60;
  long minutes = (seconds / 60) % 60;
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Stopwatch in seconds:");
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.println(runtime);
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0, 25);
  display.println("    stopwatch.ino    ");
  display.display();
  display.clearDisplay();
}


