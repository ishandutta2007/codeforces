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

int d[4444][4444];
int ds[4444];

const int mod = 1e9 + 7;

int c[4444][4444];

int main() {
    scid(n);
    d[1][1] = 1;
    for (int i = 2; i < n; i++) {
        d[i][i] = d[i][1] = 1;
        for (int j = 2; j < i; j++) {
            d[i][j] = (1LL * d[i - 1][j] * j + d[i - 1][j - 1]) % mod;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            ds[i] = (ds[i] + d[i][j]) % mod;
        }
    }

    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }

    int ans = 1;

    for (int i = 1; i < n; i++) {
        ans = (ans + 1LL * ds[n - i] * c[n][i]) % mod;
    }

    cout << ans;

    return 0;
}