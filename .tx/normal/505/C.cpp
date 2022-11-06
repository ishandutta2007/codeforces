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

int a[33333];

int dp[33333][555];

int main() {
    sciid(n, d);
    for (int i = 0; i < n; i++) {
        scid(x);
        a[x]++;
    }

    memset(dp, -1, sizeof(int) * 33333 * 555);

    dp[0][250] = 0;
    int ans = 0;
    for (int i = d; i <= 30000; i++) {
        for (int j = 0; j <= 500; j++) {
            int len = d + 250 - j;
            int x = -1e9;
            if (len <= 0 || i - len == 0 && len != d) {
                continue;
            }
            if (i - len >= 0) {
                if (j > 0 && dp[i - len][j - 1] != -1) {
                    x = max(x, dp[i - len][j - 1]);
                }
                if (dp[i - len][j] != -1) {
                    x = max(x, dp[i - len][j]);
                }
                if (dp[i - len][j + 1] != -1) {
                    x = max(x, dp[i - len][j + 1]);
                }
            }
            if (x != -1e9) {
                dp[i][j] = x + a[i];
                if (x + a[i] > ans) {
                    ans = x + a[i];
                }
            }
        }
    }

    cout << ans;

    return 0;
}