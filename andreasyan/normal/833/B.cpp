#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 35003, K = 55;

int n, k;
int a[N];
int u[N];

int t[K][N * 4];
int laz[K][N * 4];

void shi(int k, int pos)
{
    if (laz[k][pos] == 0)
        return;
    t[k][pos * 2] += laz[k][pos];
    t[k][pos * 2 + 1] += laz[k][pos];
    laz[k][pos * 2] += laz[k][pos];
    laz[k][pos * 2 + 1] += laz[k][pos];
    laz[k][pos] = 0;
}

void ubd(int k, int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[k][pos] += y;
        laz[k][pos] += y;
        return;
    }
    shi(k, pos);
    int m = (tl + tr) / 2;
    ubd(k, tl, m, l, min(m, r), y, pos * 2);
    ubd(k, m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[k][pos] = max(t[k][pos * 2], t[k][pos * 2 + 1]);
}

int qry(int k, int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[k][pos];
    int m = (tl + tr) / 2;
    return max(qry(k, tl, m, l, min(m, r), pos * 2),
               qry(k, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int dp[N][K];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (u[a[i]])
        {
            for (int j = 0; j <= k; ++j)
                ubd(j, 0, n, 0, u[a[i]] - 1, -1, 1);
        }
        u[a[i]] = i;
        for (int j = 0; j <= k; ++j)
            ubd(j, 0, n, 0, i - 1, 1, 1);
        for (int j = 1; j <= k; ++j)
            dp[i][j] = t[j - 1][1];
        for (int j = 0; j <= k; ++j)
            ubd(j, 0, n, i, i, dp[i][j], 1);
    }
    printf("%d\n", dp[n][k]);
    return 0;
}