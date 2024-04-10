#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N], b[N];

struct ban
{
    int q;
    int l, r;
    long long ansl, ansr;
    ban()
    {
        q = 0;
        l = r = 0;
        ansl = ansr = 0;
    }
    ban(int x)
    {
        q = 1;
        l = r = x;
        ansl = ansr = 0;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    if (l.q == 0 && r.q == 0)
        return res;
    if (l.l)
        res.l = l.l;
    else
        res.l = r.l;
    if (r.r)
        res.r = r.r;
    else
        res.r = l.r;
    res.q = l.q + r.q;
    if (l.q == 0)
    {
        res.ansl = r.ansl;
        res.ansr = r.ansr;
        return res;
    }
    if (r.q == 0)
    {
        res.ansl = l.ansl;
        res.ansr = l.ansr;
        return res;
    }
    res.ansr = l.ansr + r.ansr + (r.r - l.r - r.q) * 1LL * l.q;
    res.ansl = r.ansl + l.ansl + (r.l - l.l - l.q) * 1LL * r.q;
    return res;
}

ban t[N * 4];

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(x);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int qryy(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (x <= t[pos * 2].q)
        return qryy(tl, m, x, pos * 2);
    return qryy(m + 1, tr, x - t[pos * 2].q, pos * 2 + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    long long ansi = 0;
    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n, b[i], 1);
        ansi += qry(1, n, b[i] + 1, n, 1).q;
        int u = qryy(1, n, (i / 2) + (i % 2), 1);
        printf("%lld ", ansi + qry(1, n, 1, u, 1).ansr + qry(1, n, u, n, 1).ansl);
    }
    printf("\n");
    return 0;
}