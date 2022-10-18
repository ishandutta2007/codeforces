#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int dp[maxn][2];
int inf = 1e18;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int q = 1; q <= t; ++q) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        s = "#" + s;
        dp[0][0] = b;
        dp[0][1] = inf;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '0') {
                dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + b + 2 * a);
                dp[i][1] = min(dp[i - 1][0] + 2 * a + b + 2 * b, dp[i - 1][1] + 2 * b + a);
            }
            else {
                dp[i][0] = inf;
                dp[i][1] = min(dp[i - 1][0] + 2 * b + 2 * a + b, dp[i - 1][1] + 2 * b + a);
            }
        }
        //if (q == 3) cout << dp[1][0] << " " << dp[1][1] << '\n';
        cout << dp[n][0] << '\n';
    }
    return 0;
}