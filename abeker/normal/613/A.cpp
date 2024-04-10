#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;

const int MAXN = 100005;

int N;
int a, b;
int x[MAXN], y[MAXN];

void load() {
    scanf("%d%d%d", &N, &a, &b);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, y + i);
}

ld dist(ld x, ld y) {
    return x * x + y * y;
}
    
ld calc(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        if (min(y1, y2) > 0 || max(y1, y2) < 0)
            return min(dist(x1, y1), dist(x2, y2));
        return (ld)abs(x1) * abs(x1);
    }
    if (y1 == y2) {
        if (min(x1, x2) > 0 || max(x1, x2) < 0)
            return min(dist(x1, y1), dist(x2, y2));
        return (ld)abs(y1) * abs(y1);
    }
    ld k = (ld)(y2 - y1) / (x2 - x1);
    ld l = y1 - k * x1;
    ld x0 = -l / (k + 1 / k);
    ld y0 = -x0 / k;
    if (x0 < min(x1, x2) || x0 > max(x1, x2))
        return min(dist(x1, y1), dist(x2, y2));
    return dist(x0, y0);
}

ld solve() {
    for (int i = 0; i < N; i++) {
        x[i] -= a;
        y[i] -= b;
    }
    
    ld maks = 0, mini = 1e18;
    for (int i = 0; i < N; i++) {
        maks = max(maks, dist((ld)x[i], (ld)y[i]));
        mini = min(mini, calc(x[i], y[i], x[(i + 1) % N], y[(i + 1) % N]));
    }
    
    return M_PI * (maks - mini);
}

int main() {
    load();
    printf("%.18lf\n", (double)solve());
    return 0;
}