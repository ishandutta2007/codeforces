#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;

ld inv(ld val) {
    ld lo = 0, hi = 2 * M_PI;
    for (int i = 0; i < 25; i++) {
        ld mid = (lo + hi) / 2;
        if (sin(mid) - mid >= val) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main() {
    int N, R, V;
    scanf("%d%d%d", &N, &R, &V);
    while (N--) {
        int S, F;
        scanf("%d%d", &S, &F);
        ld D = ((ld)F - S) / R;
        ld rest = D - floor(D / (2 * M_PI)) * 2 * M_PI;
        ld lo = 0, hi = inv(-rest);
        for (int i = 0; i < 40; i++) {
            ld mid = (lo + hi) / 2;
            ld arg = (mid - rest) / (2 * sin(mid / 2));
            if (arg < -1 || arg > 1) lo = mid;
            else {
                ld sum = 2 * acos(arg);
                ld y = (sum + mid) / 2;
                ld x = (sum - mid) / 2;
                if (y >= 0 && y < 2 * M_PI && x >= 0 && x < 2 * M_PI) hi = mid;
                else lo = mid;
            }
        }
        printf("%.12lf\n", (double)(D + min(lo - rest, -sin(inv(rest - 2 * M_PI)))) * R / V);
    }
    return 0;
}