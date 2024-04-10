#include <bits/stdc++.h>
using namespace std;
const int N = 4003;
const long long M = 1000000007;

long long c[N][N];

int n;

long long dp[N][N];

int main()
{
    cin >> n;
    for (int i = 0; i <= n; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % M;
            dp[i + 1][j] = (dp[i + 1][j] + (dp[i][j] * j) % M) % M;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        long long sum = 0;
        for (int j = 0; j <= i; ++j)
            sum = (sum + dp[i][j]) % M;
        ans = (ans + (sum * c[n][i]) % M) % M;
    }
    cout << ans << endl;
    return 0;
}