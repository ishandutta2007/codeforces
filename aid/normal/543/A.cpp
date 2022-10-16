#include <iostream>

using namespace std;

const int MAXN = 505;
int a[MAXN], dp[2][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dp[0][0][0] = 1 % mod;
    for(int i = 0; i < m; i++) {
        int ii = (i & 1), ni = ((i + 1) & 1);
        for(int j = 0; j < n; j++)
            for(int k = 0; k <= b; k++)
                dp[ni][j][k] = 0;
        for(int j = 0; j < n; j++)
            for(int k = 0; k <= b; k++) {
                if(k + a[j] <= b)
                    dp[ni][j][k + a[j]] = (dp[ni][j][k + a[j]] +
                                           dp[ii][j][k]) % mod;
                dp[ii][j + 1][k] = (dp[ii][j + 1][k] + dp[ii][j][k]) % mod;
            }
    }
    int p = (m & 1), ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= b; j++)
            ans = (ans + dp[p][i][j]) % mod;
    cout << ans << '\n';
    return 0;
}