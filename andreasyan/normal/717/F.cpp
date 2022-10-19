#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

struct ban
{
    int q;
    int sum1;
    int minz1, mink1;
    int sum2;
    int minz2, mink2;
    int laz;
    ban()
    {
        sum1 = 0;
        minz1 = mink1 = 0;
        sum2 = 0;
        minz2 = mink2 = 0;
        laz = 0;
    }
};

ban t[N * 4];

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.q = l.q + r.q;
    if (l.q % 2 == 0)
    {
        res.sum1 = l.sum1 + r.sum1;
        res.mink1 = min(l.mink1, l.sum1 + r.mink1);
        res.minz1 = min(l.minz1, l.sum1 + r.minz1);
    }
    else
    {
        res.sum1 = l.sum1 + r.sum2;
        res.mink1 = min(l.mink1, l.sum1 + r.minz2);
        res.minz1 = min(l.minz1, l.sum1 + r.mink2);
    }
    if (l.q % 2 == 0)
    {
        res.sum2 = l.sum2 + r.sum2;
        res.mink2 = min(l.mink2, l.sum2 + r.mink2);
        res.minz2 = min(l.minz2, l.sum2 + r.minz2);
    }
    else
    {
        res.sum2 = l.sum2 + r.sum1;
        res.mink2 = min(l.mink2, l.sum2 + r.minz1);
        res.minz2 = min(l.minz2, l.sum2 + r.mink1);
    }
    return res;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos].q = 1;
        t[pos].sum1 = a[tl];
        t[pos].mink1 = a[tl];
        t[pos].sum2 = -a[tl];
        t[pos].mink2 = -a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ave(int pos, int y)
{
    t[pos].laz += y;
    if (t[pos].q % 2 == 1)
    {
        t[pos].sum1 += y;
        t[pos].sum2 -= y;
    }
    t[pos].mink1 += y;
    t[pos].mink2 -= y;
}

void shi(int pos)
{
    ave(pos * 2, t[pos].laz);
    ave(pos * 2 + 1, t[pos].laz);
    t[pos].laz = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (tl == l && tr == r)
    {
        ave(pos, y);
        return;
    }
    shi(pos);
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

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    bil(1, n, 1);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int l, r, y;
            scanf("%d%d%d", &l, &r, &y);
            ++l;
            ++r;
            ubd(1, n, l, r, y, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            ++l;
            ++r;
            ban u = qry(1, n, l, r, 1);
            if (u.mink1 >= 1 && u.minz2 >= 0)
            {
                if (u.q % 2 == 1)
                {
                    if (u.sum1 == 1)
                        printf("1\n");
                    else
                        printf("0\n");
                }
                else
                {
                    if (u.sum2 == 0)
                        printf("1\n");
                    else
                        printf("0\n");
                }
            }
            else
                printf("0\n");
        }
    }
    return 0;
}