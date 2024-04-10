#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> k(n + 1), h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    vector<vector<ll>> last(n + 1, vector<ll>(n + 1, -1));
    last[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        ll diff = k[i] - k[i - 1];
        for (int j = 0; j < i; j++) {
            if (last[j][i - 1] == -1 || last[j][i - 1] + diff < h[i])
                continue;
            last[j][i] = last[j][i - 1] + diff;
            dp[j][i] = dp[j][i - 1] + (last[j][i - 1] + 1 + last[j][i]) * (last[j][i] - last[j][i - 1]) / 2;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (k[i] - k[j] >= h[i]) {
                ll pref = 1e18;
                for (int x = 0; x <= j; x++)
                    if (last[x][j] != -1)
                        pref = min(pref, dp[x][j]);
                bool ok = true;
                for (int x = j + 1; x <= i; x++)
                    ok &= (k[x] - (k[i] - h[i])) >= h[x];
                if (ok && pref < 1e18) {
                    last[i][i] = h[i];
                    dp[i][i] = pref + h[i] * (h[i] + 1) / 2;
                } 
                break;
            }
        }
    }
    ll ans = 1e18;
    for (int j = 0; j <= n; j++)
        if (last[j][n] != -1)
            ans = min(ans, dp[j][n]);
    cout << ans << '\n';
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