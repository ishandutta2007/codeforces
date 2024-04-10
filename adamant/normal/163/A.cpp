#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int mod = 1e9 + 7;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    /*
     * dp[i][j] --  ,    i  ,     j
     */
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] %= mod;
            if(i < n && a[i] == b[j]) {
                dp[i + 1][j + 1] += dp[i][j] + 1;
            }
            dp[i][j + 1] += dp[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dp[i + 1][m];
        ans %= mod;
    }
    cout << ans << endl;
}