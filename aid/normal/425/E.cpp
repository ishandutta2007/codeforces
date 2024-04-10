#include <iostream>

using namespace std;

const int MAXN = 505, MOD = 1000 * 1000 * 1000 + 7, INV2 = 500000004;
int dp[MAXN][MAXN], inv[MAXN * MAXN], sinv[MAXN * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    inv[0] = 1;
    for(int i = 1; i <= n * (n + 1) / 2; i++)
        inv[i] = (long long)INV2 * inv[i - 1] % MOD;
    sinv[0] = inv[0];
    for(int i = 1; i <= n * (n + 1) / 2; i++) {
        sinv[i] = sinv[i - 1] + inv[i];
        if(sinv[i] >= MOD)
            sinv[i] -= MOD;
    }
    dp[0][0] = 1;
    for(int i = 0; i < n * (n + 1) / 2; i++) {
        dp[0][0] *= 2;
        if(dp[0][0] >= MOD)
            dp[0][0] -= MOD;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(dp[i][j])
                for(int k = i; k < n; k++) {
                    dp[k + 1][j + 1] =
                        (dp[k + 1][j + 1] +
                         (long long)dp[i][j] *
                         inv[(k - i) * (k - i + 1) / 2] % MOD *
                         sinv[k - i] % MOD * INV2) % MOD;
                }
    int ans = 0;
    for(int i = 0; i <= n; i++)
        ans = (ans + (long long)dp[i][l] *
               inv[(n - i) * (n - i + 1) / 2]) % MOD;
    cout << ans << '\n';
    return 0;
}