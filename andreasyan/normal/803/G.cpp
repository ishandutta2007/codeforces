#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = N * 30 * 3;
const int INF = 1000000009;

int n, k;
int a[N];

const int m = 20;
int b[N][m];
int u[N];
void pre()
{
    for (int i = 0; i < n; ++i)
    {
        b[i][0] = a[i];
        for (int j = 1; j < m; ++j)
        {
            if ((i - (1 << (j - 1))) < 0)
                break;
            b[i][j] = min(b[i][j - 1], b[(i - (1 << (j - 1)))][j - 1]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if (i >= (1 << j))
            {
                u[i] = j;
                break;
            }
        }
    }
}
int qrya(int l, int r)
{
    return min(b[r][u[r - l + 1]], b[l + (1 << u[r - l + 1]) - 1][u[r - l + 1]]);
}
int qryaa(int l, int r)
{
    if (l / n == r / n)
        return qrya(l % n, r % n);
    if (l / n + 1 == r / n)
        return min(qrya(l % n, n - 1), qrya(0, r % n));
    return qrya(0, n - 1);
}

int z;
int ll[M], rr[M];
int t[M];
int laz[M];

void ave(int tl, int tr, int pos)
{
    int m = tl + (tr - tl) / 2;
    if (!ll[pos])
    {
        ll[pos] = ++z;
        t[ll[pos]] = qryaa(tl, m);
    }
    if (!rr[pos])
    {
        rr[pos] = ++z;
        t[rr[pos]] = qryaa(m + 1, tr);
    }
}

void shi(int pos)
{
    if (laz[pos] == 0)
        return;
    laz[ll[pos]] = t[ll[pos]] = laz[pos];
    laz[rr[pos]] = t[rr[pos]] = laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    int m = tl + (tr - tl) / 2;
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        laz[pos] = y;
        t[pos] = y;
        return;
    }
    ave(tl, tr, pos);
    shi(pos);
    ubd(tl, m, l, min(m, r), y, ll[pos]);
    ubd(m + 1, tr, max(m + 1, l), r, y, rr[pos]);
    t[pos] = min(t[ll[pos]], t[rr[pos]]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    int m = tl + (tr - tl) / 2;
    if (l > r)
        return INF;
    if (tl == l && tr == r)
        return t[pos];
    ave(tl, tr, pos);
    shi(pos);
    return min(qry(tl, m, l, min(m, r), ll[pos]),
               qry(m + 1, tr, max(m + 1, l), r, rr[pos]));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    pre();
    t[0] = qrya(0, n - 1);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int l, r, y;
            scanf("%d%d%d", &l, &r, &y);
            --l;
            --r;
            ubd(0, n * k - 1, l, r, y, 0);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            --r;
            printf("%d\n", qry(0, n * k - 1, l, r, 0));
        }
    }
    return 0;
}