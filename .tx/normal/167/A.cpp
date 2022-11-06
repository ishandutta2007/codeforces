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

double getT(double v, double a, double d) {
    if (v * v / 2 / a >= d) {
        return sqrt(2 * d / a);
    }
    return v / a + (d - v * v / 2 / a) / v;
}

int main() {
    sciiid(n, a, d);
    double mx = 0;
    for (int i = 0; i < n; i++) {
        sciid(t, v);
        mx = max(mx, t + getT(v, a, d));
        printf("%.11f\n", mx);
    }

    return 0;
}