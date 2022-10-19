#include <bits/stdc++.h>
using namespace std;
const int N = 300005, M = 1000006;

int n, m;
int a[N];

int h[M];
void pre()
{
    for (int i = 1; i < M; ++i)
    {
        for (int j = i; j < M; j += i)
            h[j]++;
    }
}

long long t[N * 4];
int maxu[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = a[tl];
        maxu[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (r < l)
        return;
    if (maxu[pos] <= 2)
        return;
    if (tl == tr)
    {
        t[pos] = h[t[pos]];
        maxu[pos] = t[pos];
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

long long qry(int tl, int tr, int l, int r, int pos)
{
    if (r < l)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return qry(tl, m, l, min(m, r), pos * 2) + qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    pre();

    bil(1, n, 1);
    while (m--)
    {
        int ty, l, r;
        scanf("%d%d%d", &ty, &l, &r);
        if (ty == 1)
            ubd(1, n, l, r, 1);
        else
            printf("%lld\n", qry(1, n, l, r, 1));
    }
    return 0;
}