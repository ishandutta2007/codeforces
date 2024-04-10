#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m;
int c[N];

int p[N];
int fi(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int l[N], r[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = max(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        kpc(x, y);
    }
    for (int i = 1; i <= n; ++i)
        c[i] = fi(i);
    for (int i = 1; i <= n; ++i)
    {
        if (l[c[i]] == 0)
            l[c[i]] = i;
        r[c[i]] = max(r[c[i]], i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (l[i])
            ubd(1, n, l[i], r[i], 1);
    }
    int ll = 1;
    int ans = 0;
    while (ll <= n)
    {
        int rr = ll;
        while (1)
        {
            int u = qry(1, n, ll, rr, 1);
            if (u == rr)
                break;
            rr = u;
        }
        set<int> s;
        for (int i = ll; i <= rr; ++i)
            s.insert(c[i]);
        ans += (s.size() - 1);
        ll = rr + 1;
    }
    cout << ans << endl;
    return 0;
}