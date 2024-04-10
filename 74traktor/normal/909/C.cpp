#include<bits/stdc++.h>

using namespace std;

int const maxn = 5005;
int mod = 1e9 + 7;
int dp[maxn][maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    char lst_t, t;
    cin >> lst_t;
    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
        cin >> t;
        if (lst_t == 's') {
            int sum = 0;
            for (int j = 0; j < i - 1; ++j) {
                sum += dp[i - 1][j];
                if (sum >= mod) sum -= mod;
            }
            for (int j = 0; j < i; ++j) {
                dp[i][j] = sum;
                sum -= dp[i - 1][j];
                if (sum < 0) sum += mod;
            }
        }
        else {
            for (int j = 1; j < i; ++j) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
        lst_t = t;
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += dp[n][i];
        if (ans >= mod) ans -= mod;
    }
    cout << ans << '\n';
    return 0;
}