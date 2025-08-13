#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static void timer_task(void *arg) {
    int seconds = 0;
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
        seconds++;
        printf("elapsed: %d s\n", seconds);
    }
}

void app_main(void) {
    xTaskCreate(timer_task, "timer_task", 2048, NULL, 5, NULL);
}
