#include <bits/stdc++.h>
using namespace std;
const int N = 17;
const int M = 1000000007;

int n, m;
int t[N], g[N];

int dp[1 << N][N];

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] >> g[i];
    }
    memset(dp, 0, sizeof dp);
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                int y = (x ^ (1 << i));
                if (y == 0)
                    dp[x][i] = (dp[x][i] + 1) % M;
                for (int j = 0; j < n; ++j)
                {
                    if ((y & (1 << j)))
                    {
                        if (g[i] != g[j])
                        {
                            dp[x][i] = (dp[x][i] + dp[y][j]) % M;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                sum += t[i];
        }
        if (sum == m)
        {
            for (int i = 0; i < n; ++i)
                ans = (ans + dp[x][i]) % M;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    tt = 1;
    while (tt--)
    {
        solv();
    }
    return 0;
}