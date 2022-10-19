#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;

int n, gg;
int a[N], d[N];
long long p[N];

vector<pair<long long, int> > v;

long long t[N * 4];
long long laz[N * 4];

void shi(int pos)
{
    if (laz[pos] == 0)
        return;
    t[pos * 2] += laz[pos];
    t[pos * 2 + 1] += laz[pos];
    laz[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = p[tl - 1];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int l, int r, long long x, int pos)
{
    if (tl == l && tr == r)
    {
        t[pos] += x;
        laz[pos] += x;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, x, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, x, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, x, pos * 2);
        ubd(m + 1, tr, m + 1, r, x, pos * 2 + 1);
    }
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

long long qry(int tl, int tr, int l, int r, int pos)
{
    if (r < l)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return min(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int main()
{
    scanf("%d%d", &n, &gg);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &d[i], &a[i]);
        a[i] = gg - a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] + a[i];
    }

    long long ans = 0;
    bil(1, n, 1);
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, p[i] - qry(1, n, 1, i, 1));
        long long dd = (d[i + 1] - d[i]) * 1LL * (d[i + 1] - d[i]);
        int ll = i;
        ubd(1, n, i, i, dd, 1);
        while (!v.empty() && v.back().first <= dd)
        {
            ubd(1, n, v.back().second, ll - 1, dd - v.back().first, 1);
            ll = v.back().second;
            v.pop_back();
        }
        if (v.empty())
            v.push_back(m_p(dd, 1));
        else
            v.push_back(m_p(dd, ll));
    }
    cout << ans << endl;
    return 0;
}