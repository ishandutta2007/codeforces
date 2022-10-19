#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long INF = 1000000009;

int n, k;
long long a[N];
long long p[N];

long long t[N * 4];

void shi(int tl, int tr, int pos)
{
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    if (t[pos] == p[tr] - p[tl - 1])
    {
        t[pos * 2] = p[m] - p[tl - 1];
        t[pos * 2 + 1] = p[tr] - p[m];
    }
}

long long q;
void ubd(int tl, int tr, int l, int r, int pos)
{
    if (q == 0)
        return;

    shi(tl, tr, pos);
    int m = (tl + tr) / 2;

    if (tl == l && tr == r)
    {
        if (q >= (p[r] - p[l - 1]) - t[pos])
        {
            q -= ((p[r] - p[l - 1]) - t[pos]);
            t[pos] = (p[r] - p[l - 1]);
            return;
        }
        if (l == r)
        {
            t[pos] += q;
            q = 0;
            return;
        }
        ubd(m + 1, tr, m + 1, r, pos * 2 + 1);
        ubd(tl, m, l, m, pos * 2);
    }
    else
    {
        if (r <= m)
            ubd(tl, m, l, r, pos * 2);
        else if (l > m)
            ubd(m + 1, tr, l, r, pos * 2 + 1);
        else
        {
            ubd(m + 1, tr, m + 1, r, pos * 2 + 1);
            ubd(tl, m, l, m, pos * 2);
        }
    }

    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

long long qry(int tl, int tr, int x, int pos)
{
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;

    if (tl == tr)
        return t[pos];
    if (x <= m)
        return qry(tl, m, x, pos * 2);
    else
        return qry(m + 1, tr, x, pos * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 2; i <= n; ++i)
        cin >> a[i];
    a[1] = INF;
    ++n;
    a[n] = INF;

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    q = INF;
    ubd(1, n, 1, 1, 1);
    for (int i = 1; i < n; ++i)
    {
        q = qry(1, n, i, 1);
        if (i == 1)
            assert(q >= 0);
        ubd(1, n, i + 1, min(n, i + k), 1);
    }

    cout << qry(1, n, n, 1) << endl;
    return 0;
}