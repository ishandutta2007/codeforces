#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, q;
int a[N];
int b[N];

int t[N * 4];

void bil(int tl, int tr, int pos)
{
    t[pos] = (tr - tl + 1);
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
}

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos]--;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return qry(tl, m, l, min(m, r), pos * 2) +
        qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

void solv()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    int u = 0;
    long long ans = 0;
    bil(1, n, 1);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        x = b[x];
        if (x <= u)
        {
            ++ans;
            ubd(1, n, x, 1);
            continue;
        }
        int k = qry(1, n, 1, x - 1, 1);
        ans += (2 * k + 1);
        u = max(u, x);
        ubd(1, n, x, 1);
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