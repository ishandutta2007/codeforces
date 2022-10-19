#include <bits/stdc++.h>
using namespace std;
const int N = 14, M = 2003;

int n, m;
int a[N][M];

int jj[M];

bool so(const int& x, const int& y)
{
    int maxx = 0, maxy = 0;
    for (int i = 0; i < n; ++i)
    {
        maxx = max(maxx, a[i][x]);
        maxy = max(maxy, a[i][y]);
    }
    return maxx > maxy;
}

int maxu[1 << N];
int dp[1 << N], ndp[1 << N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    }
    for (int j = 0; j < m; ++j)
        jj[j] = j;
    sort(jj, jj + m, so);
    memset(dp, 0, sizeof dp);
    for (int jjj = 0; jjj < min(n, m); ++jjj)
    {
        int j = jj[jjj];
        for (int x = 0; x < (1 << n); ++x)
        {
            maxu[x] = 0;
            for (int si = 0; si < n; ++si)
            {
                int ymaxu = 0;
                int k = 0;
                for (int i = si; i < n; ++i, ++k)
                {
                    if ((x & (1 << k)))
                        ymaxu += a[i][j];
                }
                for (int i = 0; i < si; ++i, ++k)
                {
                    if ((x & (1 << k)))
                        ymaxu += a[i][j];
                }
                maxu[x] = max(maxu[x], ymaxu);
            }
        }
        for (int x = 0; x < (1 << n); ++x)
        {
            ndp[x] = 0;
            for (int y = x; ; y = (y - 1) & x)
            {
                ndp[x] = max(ndp[x], dp[y] + maxu[(x ^ y)]);
                if (y == 0)
                    break;
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }
    cout << dp[(1 << n) - 1] << endl;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}