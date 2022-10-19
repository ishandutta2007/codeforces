#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n, m;
int a[N];

int maxu[N * 4];
long long sum[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        sum[pos] = maxu[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
}

void ubd0(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        sum[pos] = maxu[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd0(tl, m, x, y, pos * 2);
    else
        ubd0(m + 1, tr, x, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (maxu[pos] < y)
        return;
    if (tl == tr)
    {
        maxu[pos] %= y;
        sum[pos] %= y;
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
}

long long qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return sum[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    bil(1, n, 1);
    while (m--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%I64d\n", qry(1, n, l, r, 1));
        }
        else if (ty == 2)
        {
            int l, r, y;
            scanf("%d%d%d", &l, &r, &y);
            ubd(1, n, l, r, y, 1);
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            ubd0(1, n, x, y, 1);
        }
    }
    return 0;
}