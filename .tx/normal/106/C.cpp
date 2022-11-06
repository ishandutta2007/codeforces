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

int dp[11][1111];

int a[11], b[11], c[11], d[11];

int main() {
    sciid(n, m);
    sciid(c0, d0);
    for (int i = 0; i < m; i++) {
        scii(a[i], b[i]);
        scii(c[i], d[i]);
    }
    for (int i = 1; i <= n / c0; i++) {
        dp[0][n - i * c0] = d0 * i;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j / c[i] && k <= a[i] / b[i]; k++) {
                dp[i + 1][j - k * c[i]] = max(dp[i + 1][j - k * c[i]], dp[i][j] + d[i] * k);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[m][i]);
    }

    cout << ans;
    return 0;
}