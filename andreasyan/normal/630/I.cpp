#include <bits/stdc++.h>
using namespace std;
const int N = 33;

int n;
long long dp[N * 2][N][4];
int main()
{
    cin >> n;
    dp[0][0][0] = 1;
    for (int i = 0; i < n + n - 2; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                for (int kk = 0; kk < 4; ++kk)
                {
                    if (kk != k)
                    {
                        dp[i + 1][1][kk] += dp[i][j][k];
                    }
                    else
                    {
                        dp[i + 1][j + 1][kk] += dp[i][j][k];
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n + n - 2; ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            if (i == n + n - 2)
            {
                ans += dp[i][n][k];
                continue;
            }
            int j = n + n - 2 - i;
            for (int kk = 0; kk < 4; ++kk)
            {
                if (k == kk)
                    continue;
                long long sum = 0;
                for (int jj = 0; jj < n; ++jj)
                    sum += dp[j][jj][kk];
                ans += (dp[i][n][k] * sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}