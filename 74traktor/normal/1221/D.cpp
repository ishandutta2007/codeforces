#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 3e5 + 5;
int dp[maxn][4];
int a[maxn];
int b[maxn];
int inf = 2e18;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; ++i) for (int j = 0; j <= 3; ++j) dp[i][j] = inf;
    dp[1][0] = 0, dp[1][1] = b[1], dp[1][2] = 2 * b[1], dp[1][3] = 3 * b[1];
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 3; ++j) {
            int add = j * b[i];
            for (int z = 0; z <= 3; ++z) {
                if (a[i] + j != a[i - 1] + z) dp[i][j] = min(dp[i][j], dp[i - 1][z] + add);
            }
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}