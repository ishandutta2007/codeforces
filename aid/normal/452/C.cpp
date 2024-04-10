#include <iostream>

using namespace std;

const int MAXN = 1005;
long double dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++) {
            if(j < m)
                dp[i + 1][j + 1] += dp[i][j] *
                    ((long double)(m - j) / (n * m - i));
            if(i - j < (n - 1) * m)
                dp[i + 1][j] += dp[i][j] *
                    ((long double)((n - 1) * m - (i - j)) / (n * m - i));
        }
    long double ans = 0;
    for(int i = 0; i <= n; i++)
        ans += dp[n][i] * i * i;
    ans /= n;
    cout << ans << '\n';
    return 0;
}