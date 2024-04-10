#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;

int main() {
    int w, h, alfa;
    scanf("%d%d%d", &w, &h, &alfa);
    alfa = min(alfa, 180 - alfa);
    ld a = (ld)alfa / 180 * M_PI;
    ld x = ((ld)w - h * sin(a) / (cos(a) + 1)) / 2;
    ld y = ((ld)h - w * sin(a) / (cos(a) + 1)) / 2;
    if (x < 0 || y < 0) {
        x = (ld)min(w, h);
        printf("%.15lf\n", (double)(x * x / sin(a)));
        return 0;
    }
    ld sol = (ld)w * h - (x * x + y * y) * tan(a);
    printf("%.15lf\n", (double)sol);
    return 0;
}