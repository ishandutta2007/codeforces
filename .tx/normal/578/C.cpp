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

int a[222222];
double p[222222];
int n;

void calc_s(double x, double& mn, double& mx) {
    mn = 1e31;
    mx = -1e31;
    double pmx = 0, pmn = 0;
    for (int i = 0; i < n; i++) {
        p[i] = a[i] + x;
        if (i > 0) {
            p[i] += p[i - 1];
        }
        mx = max(mx, p[i] - pmn);
        mn = min(mn, p[i] - pmx);
        pmx = max(pmx, p[i]);
        pmn = min(pmn, p[i]);
    }
}

int main() {
    sci(n);
    rea(a, n);
    double smn, smx;
    calc_s(0, smn, smx);
    if (smx + smn > 1e-9) {
        for (int i = 0; i < n; i++) {
            a[i] = -a[i];
        }
    }

    double l = -1e10, r = 1e10;

    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        calc_s(m, smn, smx);
        if (smx + smn > 1e-9) {
            r = m;
        } else {
            l = m;
        }
    }

    printf("%.11f", min(abs(smx), abs(smn)));

    return 0;
}