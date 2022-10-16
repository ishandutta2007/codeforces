#include <iostream>

using namespace std;

const int MAXN = 1005;
int a[MAXN][MAXN], dp[4][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    dp[0][0][0] = a[0][0];
    for(int i = 1; i < m; i++)
        dp[0][0][i] = dp[0][0][i - 1] + a[0][i];
    for(int i = 1; i < n; i++) {
        dp[0][i][0] = dp[0][i - 1][0] + a[i][0];
        for(int j = 1; j < m; j++)
            dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i][j];
    }
    dp[1][n - 1][0] = a[n - 1][0];
    for(int i = 1; i < m; i++)
        dp[1][n - 1][i] = dp[1][n - 1][i - 1] + a[n - 1][i];
    for(int i = n - 2; i >= 0; i--) {
        dp[1][i][0] = dp[1][i + 1][0] + a[i][0];
        for(int j = 1; j < m; j++)
            dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j - 1]) + a[i][j];
    }
    dp[2][0][m - 1] = a[0][m - 1];
    for(int i = m - 2; i >= 0; i--)
        dp[2][0][i] = dp[2][0][i + 1] + a[0][i];
    for(int i = 1; i < n; i++) {
        dp[2][i][m - 1] = dp[2][i - 1][m - 1] + a[i][m - 1];
        for(int j = m - 2; j >= 0; j--)
            dp[2][i][j] = max(dp[2][i - 1][j], dp[2][i][j + 1]) + a[i][j];
    }
    dp[3][n - 1][m - 1] = a[n - 1][m - 1];
    for(int i = m - 2; i >= 0; i--)
        dp[3][n - 1][i] = dp[3][n - 1][i + 1] + a[n - 1][i];
    for(int i = n - 2; i >= 0; i--) {
        dp[3][i][m - 1] = dp[3][i + 1][m - 1] + a[i][m - 1];
        for(int j = m - 2; j >= 0; j--)
            dp[3][i][j] = max(dp[3][i + 1][j], dp[3][i][j + 1]) + a[i][j];
    }
    int ans = -1;
    for(int i = 1; i < n - 1; i++)
        for(int j = 1; j < m - 1; j++) {
            ans = max(ans, max(dp[0][i][j - 1] + dp[1][i + 1][j] +
                               dp[2][i - 1][j] + dp[3][i][j + 1],
                               dp[0][i - 1][j] + dp[1][i][j - 1] +
                               dp[2][i][j + 1] + dp[3][i + 1][j]));
        }
    cout << ans << '\n';
    return 0;
}