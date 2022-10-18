#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    int sq = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sq += a[i] * a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sq += b[i] * b[i];
    }
    int s = accumulate(a, a + n, 0) + accumulate(b, b + n, 0);
    int dp[n + 1][s + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= s; j++) {
            if(dp[i][j]) {
                dp[i + 1][j + a[i]] = 1;
                dp[i + 1][j + b[i]] = 1;
            }
        }
    }
    int ans = 1e18;
    for(int i = 0; i <= s; i++) {
        if(dp[n][i]) {
            ans = min(ans, sq * (n - 2) + (i * i + (s - i) * (s - i)));
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