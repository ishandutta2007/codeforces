#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = tr;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = tr;
}

int mer(int l, int r)
{
    if (r == -1)
        return l;
    return r;
}
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = -1;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (r < l)
        return -1;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    long long ans = 0;
    bil(1, n, 1);
    for (int i = 1; i <= n; ++i)
    {
        int x = qry(1, n, 1, a[i], 1);
        if (x != -1)
        {
            ans += x;
            ubd(1, n, x, 1);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}