#include <bits/stdc++.h>
using namespace std;
const int N = 20;

int n, m, k;
int a[N];
int b[N][N];

long long dp[1 << N][N];
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < k; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        b[x][y] = z;
    }
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                int y = (x ^ (1 << i));
                if (y == 0)
                    dp[x][i] = a[i];
                for (int j = 0; j < n; ++j)
                {
                    if ((y & (1 << j)))
                        dp[x][i] = max(dp[x][i], dp[y][j] + b[j][i] + a[i]);
                }
            }
        }
    }
    long long ans = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        int q = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ++q;
        }
        if (q == m)
        {
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    ans = max(ans, dp[x][i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}