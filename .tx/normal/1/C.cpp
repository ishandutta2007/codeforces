#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

const double PI = acos(-1.0);

bool isInt(double x) {
    return x - floor(x) < 5e-5 || ceil(x) - x < 5e-5;
}

int main() {
    init_cin
    double x[3], y[3];
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }
    double a[2], b[2], c[2];
    for (int i = 0; i < 2; i++) {
        a[i] = x[i + 1] - x[i];
        b[i] = y[i + 1] - y[i];
        c[i] = -a[i] * (x[i] + x[i + 1]) / 2 - b[i] * (y[i] + y[i + 1]) / 2;
    }

    double d = a[0] * b[1] - a[1] * b[0];
    double d1 = -c[0] * b[1] + c[1] * b[0];
    double d2 = -a[0] * c[1] + a[1] * c[0];

    double ox = d1 / d;
    double oy = d2 / d;

    double distSq = (x[0] - ox) * (x[0] - ox) + (y[0] - oy) * (y[0] - oy);

    double ang[3];
    for (int i = 0; i < 3; i++) {
        ang[i] = atan2(y[i] - oy, x[i] - ox);
    }

    double minSq = 1e9;

    for (int i = 3; i <= 100; i++) {
        double cAng = 2 * PI / i;
        bool ok = true;
        for (int j = 0; j < 3; j++) {
            if (!isInt(abs(ang[j] - ang[(j + 1) % 3]) / cAng)) {
                ok = false;
                break;
            }
        }

        if (ok) {
            double sq = distSq * sin(cAng) * i / 2;
            minSq = min(minSq, sq);
        }
    }

    printf("%.11f", minSq);

    return 0;
}