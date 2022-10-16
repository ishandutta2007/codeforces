#include <iostream>

using namespace std;

const int MAXN = 2005, MOD = 1000 * 1000 * 1000 + 7;
int dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        dp[0][i] = 1;
    for(int i = 0; i < k - 1; i++)
        for(int j = 1; j <= n; j++)
            for(int k = j; k <= n; k += j)
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = (ans + dp[k - 1][i]) % MOD;
    cout << ans << '\n';
    return 0;
}