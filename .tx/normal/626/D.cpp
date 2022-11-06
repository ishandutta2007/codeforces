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

int d[5555];
int a[2222];
int ps[5555];

int main() {
    scid(n);
    rea(a, n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            d[abs(a[i] - a[j])]++;
        }
    }
    for (int i = 5000; i >= 0; i--) {
        ps[i] = ps[i + 1] + d[i];
    }

    double ans = 0;

    for (int i = 1; i <= 5000; i++) {
        for (int j = 1; j <= 5000 - i; j++) {
            double p1 = d[i] / (0.5 * n * (n - 1));
            double p2 = d[j] / (0.5 * n * (n - 1));
            double p3 = ps[i + j + 1] / (0.5 * n * (n - 1));
            ans += p1 * p2 * p3;
        }
    }
    printf("%.11f", ans);

    return 0;
}