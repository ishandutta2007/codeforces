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
typedef long double ldouble;

using namespace std;

int c[1000];

int dm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(m, d);
        sciid(p, t);
        for (int j = 1; j < m; j++) {
            d += dm[j];
        }
        for (int j = d - t; j < d; j++) {
            c[j + 500] += p;
        }
    }
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        ans = max(ans, c[i]);
    }
    cout << ans;

    return 0;
}