#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, qq;

int c[N * 4];
long long laz[N * 4];
long long sum[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        c[pos] = tl;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    c[pos] = -1;
}

void shi(int tl, int tr, int pos)
{
    if (c[pos] != -1)
    {
        c[pos * 2] = c[pos * 2 + 1] = c[pos];
        c[pos] = -1;
    }
    int m = (tl + tr) / 2;
    sum[pos * 2] += laz[pos] * (m - tl + 1);
    sum[pos * 2 + 1] += laz[pos] * (tr - m);
    laz[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        if (c[pos] != -1)
        {
            sum[pos] += (r - l + 1) * 1LL * abs(y - c[pos]);
            laz[pos] += abs(y - c[pos]);
            c[pos] = y;
            return;
        }
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
    if (c[pos * 2] == c[pos * 2 + 1])
        c[pos] = c[pos * 2];
}

long long qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return sum[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int main()
{
    scanf("%d%d", &n, &qq);
    bil(1, n, 1);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int l, r, y;
            scanf("%d%d%d", &l, &r, &y);
            ubd(1, n, l, r, y, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", qry(1, n, l, r, 1));
        }
    }
    return 0;
}