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

lint sqdist(lint x1, lint y1, lint x2, lint y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

double dist(lint x1, lint y1, lint x2, lint y2) {
    return sqrt(sqdist(x1, y1, x2, y2));
}

int x[111];

int main() {
    sciiid(n, vb, vs);
    rea(x, n);
    sciid(xu, yu);
    double opt = 1e18;
    int mn = -1;
    for (int i = 1; i < n; i++) {
        double t = 1.0 * x[i] / vb + dist(x[i], 0, xu, yu) / vs;
//        if (abs(t - opt) < 1e-9) {
//            if (sqdist(x[i], 0, xu, yu) < sqdist(x[mn], 0, xu, yu)) {
//                mn = i;
//            }
//        } else if (t < opt - 1e-9) {
//            opt = t;
//            mn = i;
//        }
        if (t < opt + 1e-9) {
            opt = t;
            mn = i;
        }
    }
    cout << mn + 1;

    return 0;
}