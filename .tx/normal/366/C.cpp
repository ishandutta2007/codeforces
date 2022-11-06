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

int a[111], b[111];

int d[111][222222];

int main() {
    sciid(n, k);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    for (int i = 0; i < n; i++) {
        sci(b[i]);
        b[i] *= k;
    }
    for (int i = 0; i < 222222; i++) {
        d[0][i] = -1;
    }
    d[0][111111] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 222222; j++) {
            d[i + 1][j] = d[i][j];
        }
        int dif = a[i] - b[i];
        for (int j = 0; j < 222222; j++) {
            if (j - dif < 0 || j - dif >= 222222) {
                continue;
            }
            if (d[i][j - dif] != -1) {
                d[i + 1][j] = max(d[i + 1][j], d[i][j - dif] + a[i]);
            }
        }
    }

    int ans = d[n][111111];
    if (ans == 0) {
        ans = -1;
    }
    cout << ans;

    return 0;
}