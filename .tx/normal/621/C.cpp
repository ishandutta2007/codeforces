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

double a[111111];

int main() {
    sciid(n, p);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = 1.0 * (y / p - (x - 1) / p) / (y - x + 1);
    }
    a[n] = a[0];
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1 - (1 - a[i]) * (1 - a[i + 1]);
    }

    printf("%.11f", ans * 2000);


    return 0;
}