#include <bits/stdc++.h>

using namespace std;

const int LIM = (1 << 18);
const int MAXN = 18;
long long dp[LIM][MAXN];
int d[MAXN][MAXN];
int a[MAXN];

int main() {
    int n, m, k, u, v, c;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[(1 << i)][i] = a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> u >> v >> c;
        u--, v--;
        d[u][v] = c;
    }
    int lim = (1 << n);
    for (int mask = 0; mask < lim; mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) {
                    dp[mask + (1 << j)][j] = max(dp[mask + (1 << j)][j], dp[mask][i] + d[i][j] + a[j]);
                }
            }
        }
    }
    long long ans = 0;
    for (int mask = 0; mask < lim; mask++) {
        if (__builtin_popcount(mask) == m) {
            for (int i = 0; i < n; i++) {
                ans = max(ans, dp[mask][i]);
            }
        }
    }
    cout << ans << endl;
}