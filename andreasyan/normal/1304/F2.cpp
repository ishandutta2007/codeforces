#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 20004;

int n, m, k;
int a[N][M];

int dp[N][M];

int maxu[M * 4];
int laz[M * 4];

void shi(int pos)
{
    if (laz[pos] == 0)
        return;
    maxu[pos * 2] += laz[pos];
    laz[pos * 2] += laz[pos];
    maxu[pos * 2 + 1] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        maxu[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    }
    for (int i = 1; i <= n; ++i)
    {
        memset(maxu, 0, sizeof maxu);
        memset(laz, 0, sizeof laz);
        for (int j = 1; j <= m - k + 1; ++j)
        {
            ubd(1, m, j, j, dp[i - 1][j], 1);
        }
        int sum = 0;
        for (int j = 1; j <= k; ++j)
        {
            ubd(1, m, 1, j, -a[i][j], 1);
            sum += a[i][j];
            sum += a[i + 1][j];
        }
        for (int j = 1; j <= m - k + 1; ++j)
        {
            dp[i][j] = max(0, maxu[1]) + sum;
            sum -= a[i][j];
            sum -= a[i + 1][j];
            sum += a[i][j + k];
            sum += a[i + 1][j + k];
            ubd(1, m, max(1, j - k + 1), j, a[i][j], 1);
            ubd(1, m, j + 1, min(j + k, m - k + 1), -a[i][j + k], 1);
        }
    }
    int ans = 0;
    for (int j = 1; j <= m - k + 1; ++j)
        ans = max(ans, dp[n][j]);
    printf("%d\n", ans);
    return 0;
}