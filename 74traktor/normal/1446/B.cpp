#include<bits/stdc++.h>

using namespace std;

int dp[5005][5005];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 2;
            else dp[i][j] = max(0, dp[i - 1][j - 1] - 2);
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
            dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}