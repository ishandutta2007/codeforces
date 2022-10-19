#include <bits/stdc++.h>
using namespace std;
const int N = 66, INF = 1000000009;

int n, m, q;
int a[N][N][N];

int dp[N][N][N];

int main()
{
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                cin >> a[i][x][y];
            }
        }
        for (int z = 1; z <= n; ++z)
        {
            for (int x = 1; x <= n; ++x)
            {
                for (int y = 1; y <= n; ++y)
                {
                    a[i][x][y] = min(a[i][x][y], a[i][x][z] + a[i][z][y]);
                }
            }
        }
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                    dp[i][j][k] = INF;
    for (int i = 0; i < m; ++i)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                dp[x][y][0] = min(a[i][x][y], dp[x][y][0]);
            }
        }
    }
    for (int k = 0; k < n; ++k)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                for (int hy = 1; hy <= n; ++hy)
                {
                    dp[x][hy][k + 1] = min(dp[x][hy][k + 1], dp[x][y][k] + dp[y][hy][0]);
                }
            }
        }
    }

    while (q--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        k = min(k, n);
        cout << dp[x][y][k] << endl;
    }
    return 0;
}