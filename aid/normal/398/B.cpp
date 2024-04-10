#include <iostream>

using namespace std;

const int MAXN = 2005;
char rc[MAXN], cc[MAXN];
double dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        rc[r] = true;
        cc[c] = true;
    }
    for(int i = 1; i <= n; i++)
        dp[0][i] = (double)n / i + dp[0][i - 1];
    for(int i = 1; i <= n; i++) {
        dp[i][0] = (double)n / i + dp[i - 1][0];
        for(int j = 1; j <= n; j++) {
            double p = (double)(i * n - i * j + j * n) / (n * n);
            dp[i][j] = (1 + (double)i / n * (1 - (double)j / n) * dp[i - 1][j] +
                        (double)j / n * (1 - (double)i / n) * dp[i][j - 1] +
                        (double)(i * j) / (n * n) * dp[i - 1][j - 1]) / p;
        }
    }
    int rn = 0;
    for(int i = 0; i < n; i++)
        rn += rc[i];
    int cn = 0;
    for(int i = 0; i < n; i++)
        cn += cc[i];
    cout << dp[n - rn][n - cn] << '\n';
    return 0;
}