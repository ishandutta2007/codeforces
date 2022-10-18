#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n, m;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 2;
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = max<int>({1, dp[i - 1][j], dp[i][j - 1]}) - 1;
            }
        }
    }
    cout << ans << "\n";
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}