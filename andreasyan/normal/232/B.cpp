#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 102;
const long long M = 1000000007;

long long ast(long long x, long long n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        long long y = ast(x, n / 2);
        return (y * y) % M;
    }
    else
    {
        long long y = ast(x, n - 1);
        return (y * x) % M;
    }
}

int n;
long long m;
int k;

long long dp[N][N * N];

long long c[N][N];
long long cn[N];

int32_t main()
{
    cin >> n >> m >> k;

    c[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }

    for (int j = 0; j <= n; ++j)
        cn[j] = ast(c[n][j], m / n);

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            for (int v = 0; v <= min(n, j); ++v)
            {
                if (i <= m % n)
                    dp[i][j] = (dp[i][j] + (dp[i - 1][j - v] * ((cn[v] * c[n][v]) % M)) % M) % M;
                else
                    dp[i][j] = (dp[i][j] + (dp[i - 1][j - v] * (cn[v] * 1) % M) % M) % M;
            }
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}