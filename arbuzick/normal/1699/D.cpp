#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 5;

int dp[maxn][maxn];

int a[maxn], cnt[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = -n;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[i + 1][a[i]] = max(dp[i + 1][a[i]], dp[i][a[i]] + 1);
        int mx = -1;
        for (int j = i; j < n; ++j) {
            cnt[a[j]]++;
            if (mx == -1 || cnt[a[j]] > cnt[mx]) {
                mx = a[j];
            }
            if ((j - i + 1) % 2 == 0) {
                dp[j + 1][mx] = max(dp[j + 1][mx], dp[i][mx]);
            }
            if ((j - i + 1) % 2 == 0 && cnt[mx] * 2 <= j - i + 1) {
                if (i == 0) {
                    for (int v = 0; v < n; ++v) {
                        dp[j + 1][v] = max(dp[j + 1][v], 0);
                    }
                } else {
                    dp[j + 1][a[i - 1]] = max(dp[j + 1][a[i - 1]], dp[i][a[i - 1]]);
                }
            }
        }
        for (int j = i; j < n; ++j) {
            cnt[a[j]] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}