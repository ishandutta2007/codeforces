#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long INF = 1000000009000000009;

int n, m, k, q;

int l[N], r[N];

bool c[N];
int ll[N], rr[N];

int u[N];

long long go(int x, int uu, bool z)
{
    if (!z)
    {
        return abs(x - r[uu]) + abs(r[uu] - l[uu]);
    }
    else
    {
        return abs(x - l[uu]) + abs(l[uu] - r[uu]);
    }
}

long long dpl, dpr;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (l[x] == 0)
        {
            l[x] = r[x] = y;
        }
        else
        {
            l[x] = min(l[x], y);
            r[x] = max(r[x], y);
        }
    }
    for (int i = 0; i < q; ++i)
    {
        int y;
        scanf("%d", &y);
        c[y] = true;
    }
    for (int i = 1; i <= m; ++i)
    {
        if (c[i])
            ll[i] = i;
        else
            ll[i] = ll[i - 1];
    }
    for (int i = m; i >= 1; --i)
    {
        if (c[i])
            rr[i] = i;
        else
            rr[i] = rr[i + 1];
    }
    int uu = 0;
    for (int i = n; i >= 1; --i)
    {
        u[i] = uu;
        if (l[i])
            uu = i;
    }
    if (!l[1])
        l[1] = r[1] = 1;
    uu = 1;
    dpl = go(1, 1, false);
    dpr = go(1, 1, true);
    while (1)
    {
        if (u[uu] == 0)
        {
            cout << min(dpl, dpr) << endl;
            return 0;
        }
        long long ndpl = INF, ndpr = INF;
        // from r to rr
        if (rr[r[uu]])
        {
            int x = r[uu];
            int y = rr[r[uu]];
            ndpl = min(ndpl, dpr + abs(x - y) + abs(uu - u[uu]) + go(y, u[uu], false));
            ndpr = min(ndpr, dpr + abs(x - y) + abs(uu - u[uu]) + go(y, u[uu], true));
        }
        // from r to ll
        if (ll[r[uu]])
        {
            int x = r[uu];
            int y = ll[r[uu]];
            ndpl = min(ndpl, dpr + abs(x - y) + abs(uu - u[uu]) + go(y, u[uu], false));
            ndpr = min(ndpr, dpr + abs(x - y) + abs(uu - u[uu]) + go(y, u[uu], true));
        }
        // from l to ll
        if (ll[l[uu]])
        {
            int x = l[uu];
            int y = ll[l[uu]];
            ndpl = min(ndpl, dpl + abs(x - y) + abs(uu - u[uu]) + go(y, u[uu], false));
            ndpr = min(ndpr, dpl + abs(x - y) + abs(uu - u[uu]) + go(y, u[uu], true));
        }
        // from l to rr
        if (rr[l[uu]])
        {
            int x = l[uu];
            int y = rr[l[uu]];
            ndpl = min(ndpl, dpl + abs(x - y) + abs(uu - u[uu]) + go(y, u[uu], false));
            ndpr = min(ndpr, dpl + abs(x - y) + abs(uu - u[uu]) + go(y, u[uu], true));
        }
        dpl = ndpl;
        dpr = ndpr;
        uu = u[uu];
    }
    return 0;
}