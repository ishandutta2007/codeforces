#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

int x1, y1, x2, y2;
int vmax, t;
int vx, vy, wx, wy;

void load() {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d%d", &vmax, &t);
    scanf("%d%d%d%d", &vx, &vy, &wx, &wy);
}

ld sqr(ld x) {
    return x * x;
}

bool check(ld val) {
    ld x = x1 + min((ld)t, val) * vx + max(val - (ld)t, (ld)0) * wx;
    ld y = y1 + min((ld)t, val) * vy + max(val - (ld)t, (ld)0) * wy;
    return sqr(x2 - x) + sqr(y2 - y) <= sqr((ld)vmax * val);
}

ld solve() {
    ld lo = 0, hi = 1e9;
    for (int i = 0; i < 1000; i++) {
        ld mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}

int main() {
    load();
    printf("%.18lf\n", (double)solve());
    return 0;
}