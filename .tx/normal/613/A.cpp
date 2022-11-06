#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

const int N = 111111;
int x[N], y[N];

lint vec(lint x1, lint y1, lint x2, lint y2) {
    return x1 * y2 - x2 * y1;
}

lint sign(lint x) {
    if (x < 0) {
        return -1;
    }
    if (x > 0) {
        return 1;
    }
    return 0;
}

double dist(lint x1, lint y1, lint x2, lint y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    sciiid(n, px, py);
    double minDist = 1e18, maxDist = 0;
    for (int i = 0; i < n; i++) {
        scii(x[i], y[i]);
    }
    for (int i = 0; i < n; i++) {
        maxDist = max(maxDist, dist(x[i], y[i], px, py));
        lint x0 = x[i];
        lint x1 = x[(i + 1) % n];
        lint y0 = y[i];
        lint y1 = y[(i + 1) % n];
        lint a = y1 - y0;
        lint b = x0 - x1;
        lint c = -x0 * a - y0 * b;

        double dToLine = abs(a * px + b * py + c) / sqrt(a * a + b * b);

        lint s1 = sign(vec(x0 - px, y0 - py, a, b));
        lint s2 = sign(vec(x1 - px, y1 - py, a, b));
        if (s1 == s2) {
            dToLine = min(dist(x0, y0, px, py), dist(x1, y1, px, py));
        }
        minDist = min(minDist, dToLine);
    }
    const double PI = acos(-1.0);
    printf("%.11f", maxDist * maxDist * PI - minDist * minDist * PI);

    return 0;
}