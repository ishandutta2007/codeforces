#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, INF = 1000000009;

int n, s, d;
int a[N];

const int m = 19;
int minu[N][m], maxu[N][m];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return INF;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int dp[N];

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d%d%d", &n, &s, &d);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        minu[i][0] = maxu[i][0] = a[i];
        for (int j = 1; j < m; ++j)
        {
            if ((i - (1 << j) + 1) >= 1)
            {
                minu[i][j] = min(minu[i][j - 1], minu[i - (1 << (j - 1))][j - 1]);
                maxu[i][j] = max(maxu[i][j - 1], maxu[i - (1 << (j - 1))][j - 1]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int yminu = INF, ymaxu = -INF;
        int x = i;
        for (int j = m - 1; j >= 0; --j)
        {
            if ((x - (1 << j) + 1) >= 1)
            {
                if (max(ymaxu, maxu[x][j]) - min(yminu, minu[x][j]) <= s)
                {
                    ymaxu = max(ymaxu, maxu[x][j]);
                    yminu = min(yminu, minu[x][j]);
                    x = (x - (1 << j));
                }
            }
        }
        dp[i] = min(INF, qry(0, n, x, i - d, 1) + 1);
        ubd(0, n, i, dp[i], 1);
    }
    if (dp[n] == INF)
        printf("-1\n");
    else
        printf("%d\n", dp[n]);
    return 0;
}