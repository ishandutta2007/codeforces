#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int dp[n + 1][360];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < 360; j++) {
            dp[i + 1][(j + a[i]) % 360] |= dp[i][j];
            dp[i + 1][(j + 360 - a[i]) % 360] |= dp[i][j];
        }
    }
    cout << (dp[n][0] ? "YES" : "NO") << endl;
    return 0;
}