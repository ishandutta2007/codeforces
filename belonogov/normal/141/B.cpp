#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const long double eps = 1e-9;

int main()
{
   int a, _x, _y;
    long double x, y;
    scanf("%d%d%d", &a, &_x, &_y);
    if (_y % a == 0){
        printf("-1");
        return 0;
    }
    x = (long double)_x / a;
    y = (long double)_y / a;
    if (y < 0){
        printf("-1");
        return 0;
    }
    if (y <= 1 + eps){
        if (abs(x) < 0.5)
            printf("1");
        else
            printf("-1");
        return 0;
    }
    if (((int) y) % 2 == 1){
         if (abs(x) < 0.5)
            printf("%d", (int) y + ((int) y) / 2  + 1);
        else
            printf("-1");
        return 0;
    }
    if (_x == 0){
        printf("-1");
        return 0;
    }
    if (abs(x) < 1){
        if (x > 0)
            printf("%d", (int) y + ((int) y)/ 2 + 1);
        else
            printf("%d", (int) y + ((int) y)/ 2);
        return 0;
    }
    printf("-1");
    return 0;
}