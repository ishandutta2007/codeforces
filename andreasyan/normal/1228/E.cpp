#include <bits/stdc++.h>
using namespace std;
const int N = 255, M = 1000000007;

int n, k;

int c[N][N];
int ast[N], astmm[N];
void pre()
{
    ast[0] = 1;
    astmm[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        ast[i] = (ast[i - 1] * 1LL * k) % M;
        astmm[i] = (astmm[i - 1] * 1LL * (k - 1)) % M;
    }
    for (int i = 0; i <= n; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
}

int dp[N][N];
int main()
{
    cin >> n >> k;
    pre();
    dp[0][n] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int jj = 0; jj <= j; ++jj)
            {
                dp[i + 1][jj] = (dp[i + 1][jj] + ((dp[i][j] * 1LL * ast[n - j]) % M * 1LL * c[j][j - jj]) % M * astmm[jj]) % M;
                if (j == jj)
                {
                    dp[i + 1][jj] = (dp[i + 1][jj] - ((dp[i][j] * 1LL * astmm[n - j]) % M * 1LL * astmm[jj]) % M + M) % M;
                }
            }
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}