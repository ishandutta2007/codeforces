#include <bits/stdc++.h>
using namespace std;
const int N = 502;
const long long INF = 1000000000000000018;

int n;

long long dp[N][N];

int pp(int i)
{
    if (i == n)
        return 1;
    return i + 1;
}

int main()
{
    cin >> n;
    for (int d = 2; d < n; ++d)
    {
        for (int l = 1; l <= n; ++l)
        {
            int r = (l - 1 + d) % n + 1;
            dp[l][r] = INF;
            for (int i = pp(l); i != r; i = pp(i))
            {
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r] + l * i * r);
            }
        }
    }
    long long ans = INF;
    for (int i = 2; i < n; ++i)
    {
        for (int j = pp(i); j != 1; j = pp(j))
            ans = min(ans, dp[1][i] + dp[i][j] + dp[j][1] + i * j);
    }
    cout << ans << endl;
    return 0;
}