#include <bits/stdc++.h>
#include <cassert>
#include <functional>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            (res *= a) %= MOD;
        p >>= 1;
        (a *= a) %= MOD;
    }
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1));
    // dp[add][rem]
    ll inv2 = binpow(2, MOD - 2);
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= m; i++) {
            // (i, j) -> (i + 1, j - 1) + val
            //        -> (i, j - 1) - val
            if (i + j < m)
                continue;
            if (i == m) {
                dp[i][j] = dp[i][j - 1];
                continue;
            }
            if (i + j - 1 < m) {
                dp[i][j] = (dp[i + 1][j - 1] + k) % MOD;
                continue;
            }
            ll val = (dp[i][j - 1] - dp[i + 1][j - 1] + MOD) * inv2 % MOD;
            dp[i][j] = (dp[i + 1][j - 1] + val) % MOD;
        }
    }
    cout << dp[0][n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}