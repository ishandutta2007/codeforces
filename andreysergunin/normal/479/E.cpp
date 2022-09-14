#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
    long long n, a, b, k, i, j, t;
    long long dp[5001][5001];
    cin >> n >> a >> b >>k;
    if (a > b)
    {
        a = n + 1 - a;
        b = n + 1 - b;
    }
    for (i = b - 1; i > 0; i--)
        dp[i][0] = b - i;
    for (i = 0; i < k; i++)
        dp[b][i] = 0;
    for (j = 1; j <= k; j++)
    {
        for (i = b - 1; i > 0; i--)
        {
            if (1 > 2 * i - b + 1)
                t = 1;
            else
                t = 2 * i - b + 1;
            dp[i][j] = (dp[i + 1][j] + dp[t][j - 1] - dp[i][j - 1] + dp[i + 1][j - 1]) % 1000000007;
        }
    }

    cout << (dp[a][k] - dp[a + 1][k] + 1000000007) % 1000000007;

}