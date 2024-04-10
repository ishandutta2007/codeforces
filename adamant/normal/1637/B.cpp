#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    int a[n];
    int mex[n][n];
    for(int i = 0; i < n; i++) {
        set<int> nonp;
        for(int j = 0; j <= n; j++) {
            nonp.insert(j);
        }
        cin >> a[i];
        for(int j = i; j >= 0; j--) {
            nonp.erase(a[j]);
            mex[j][i] = *begin(nonp);
        }
    }
    int dp[n][n];
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            dp[i][j] = mex[i][j] + 1;
            for(int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + mex[k + 1][j] + 1);
            }
            ans += dp[i][j];
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}