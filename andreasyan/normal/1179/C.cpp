#include <bits/stdc++.h>
using namespace std;
const int N = 1000006, M = 1000000;
struct ban
{
    int sum;
    int minu;
    int laz;
    ban()
    {
        sum = 0;
        minu = 0;
        laz = 0;
    }
};

ban t[N * 4];
void shi(int tl, int tr, int pos)
{
    if (!t[pos].laz)
        return;
    int m = (tl + tr) / 2;
    t[pos * 2].sum += (m - tl + 1) * t[pos].laz;
    t[pos * 2].minu += t[pos].laz;
    t[pos * 2].laz += t[pos].laz;
    t[pos * 2 + 1].sum += (tr - m) * t[pos].laz;
    t[pos * 2 + 1].minu += t[pos].laz;
    t[pos * 2 + 1].laz += t[pos].laz;
    t[pos].laz = 0;
}

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.minu = min(l.minu, r.minu);
    res.sum = l.sum + r.sum;
    return res;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (tl == l && tr == r)
    {
        t[pos].sum += (r - l + 1) * y;
        t[pos].minu += y;
        t[pos].laz += y;
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, y, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, y, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, y, pos * 2);
        ubd(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    }
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int pos)
{
    if (tl == tr)
        return tl;
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    if (t[pos * 2 + 1].minu < 0)
        return qry(m + 1, tr, pos * 2 + 1);
    else
        return qry(tl, m, pos * 2);
}

int n, m;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        ubd(1, M, 1, a[i], -1, 1);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &b[i]);
        ubd(1, M, 1, b[i], 1, 1);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int i, x;
            scanf("%d%d", &i, &x);
            ubd(1, M, 1, a[i], 1, 1);
            a[i] = x;
            ubd(1, M, 1, a[i], -1, 1);
        }
        else
        {
            int i, x;
            scanf("%d%d", &i, &x);
            ubd(1, M, 1, b[i], -1, 1);
            b[i] = x;
            ubd(1, M, 1, b[i], 1, 1);
        }
        if (t[1].minu >= 0)
            printf("-1\n");
        else
            printf("%d\n", qry(1, M, 1));
    }
    return 0;
}