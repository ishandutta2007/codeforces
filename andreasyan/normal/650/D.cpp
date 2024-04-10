#include <bits/stdc++.h>
using namespace std;
const int N = 400005;

int n, q;
int a[N];
int xx[N], yy[N];

int sans;

int zz;
int ll[N * 45], rr[N * 45], u[N * 45];

int ubd(int tl, int tr, int x, int y, int pos)
{
    int ypos = ++zz;
    u[ypos] = max(u[pos], y);
    if (tl == tr)
        return ypos;
    int m = (tl + tr) / 2;
    if (x <= m)
    {
        ll[ypos] = ubd(tl, m, x, y, ll[pos]);
        rr[ypos] = rr[pos];
    }
    else
    {
        ll[ypos] = ll[pos];
        rr[ypos] = ubd(m + 1, tr, x, y, rr[pos]);
    }
    return ypos;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (pos == 0)
        return 0;
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return u[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, ll[pos]);
    if (l > m)
        return qry(m + 1, tr, l, r, rr[pos]);
    return max(qry(tl, m, l, m, ll[pos]), qry(m + 1, tr, m + 1, r, rr[pos]));
}

int z;

int tl[N], tr[N];
int dpl[N], dpr[N];

int qryy(int x, int y)
{
    return qry(1, z, 1, y - 1, tl[x - 1]) + 1 + qry(1, z, y + 1, z, tr[x + 1]);
}

bool c[N];
int qq[N];

int main()
{
    scanf("%d%d", &n, &q);
    vector<int> v;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    for (int i = 0; i < q; ++i)
    {
        scanf("%d%d", &xx[i], &yy[i]);
        v.push_back(yy[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++z;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i] = mp[a[i]];
    }
    for (int i = 0; i < q; ++i)
    {
        yy[i] = mp[yy[i]];
    }
    for (int i = 1; i <= n; ++i)
    {
        dpl[i] = qry(1, z, 1, a[i] - 1, tl[i - 1]) + 1;
        tl[i] = ubd(1, z, a[i], dpl[i], tl[i - 1]);
    }
    for (int i = n; i >= 1; --i)
    {
        dpr[i] = qry(1, z, a[i] + 1, z, tr[i + 1]) + 1;
        tr[i] = ubd(1, z, a[i], dpr[i], tr[i + 1]);
    }
    for (int i = 1; i <= n; ++i)
        sans = max(sans, dpl[i]);
    for (int i = 1; i <= n; ++i)
    {
        int yans = qryy(i, a[i]);
        if (yans == sans)
        {
            c[i] = true;
            qq[dpl[i]]++;
        }
    }
    for (int i = 0; i < q; ++i)
    {
        int x, y;
        x = xx[i];
        y = yy[i];
        int yans = qryy(x, y);
        if (c[x] && qq[dpl[x]] == 1)
            yans = max(yans, sans - 1);
        else
            yans = max(yans, sans);
        printf("%d\n", yans);
    }
    return 0;
}