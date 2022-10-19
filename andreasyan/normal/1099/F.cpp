#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1000006;

int n;
long long T;
long long q[N], t[N];
vector<pair<int, long long> > a[N];

long long tt[N * 4], qq[N * 4];
void ubd(int tl, int tr, long long x, long long y, int pos)
{
    if (tl == tr)
    {
        qq[pos] += y;
        tt[pos] += (y * x);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    tt[pos] = tt[pos * 2] + tt[pos * 2 + 1];
    qq[pos] = qq[pos * 2] + qq[pos * 2 + 1];
}

long long byn(long long t, long long t0, long long r)
{
    long long l = 0;
    while ((r - l) > 4)
    {
        long long m = (l + r) / 2;
        if (m * t0 <= t)
            l = m;
        else
            r = m;
    }
    for (long long m = r; m >= l; --m)
        if (m * t0 <= t)
            return m;
}

long long qry(int tl, int tr, long long ti, int pos)
{
    if (tl == tr)
    {
        return byn(ti, tl, qq[pos]);
    }
    int m = (tl + tr) / 2;
    if (ti >= tt[pos * 2])
        return qq[pos * 2] + qry(m + 1, tr, ti - tt[pos * 2], pos * 2 + 1);
    else
        return qry(tl, m, ti, pos * 2);
}

long long ans[N];
void dfs(int x, long long ll)
{
    ubd(1, N - 1, t[x], q[x], 1);
    long long max1 = 0, max2 = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        dfs(h, ll + a[x][i].second);
        if (ans[h] > max1)
        {
            max2 = max1;
            max1 = ans[h];
        }
        else if (ans[h] > max2)
            max2 = ans[h];
    }
    ans[x] = max(max2, qry(1, N - 1, T - ll - ll, 1));
    if (x == 1)
        ans[x] = max(ans[x], max1);
    ubd(1, N - 1, t[x], -q[x], 1);
}

int main()
{
    //freopen("input2.txt", "r", stdin);
    scanf("%d%lld", &n, &T);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &q[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &t[i]);
    for (int y = 2; y <= n; ++y)
    {
        int x;
        scanf("%d", &x);
        int z;
        scanf("%d", &z);
        a[x].push_back(m_p(y, z));
    }
    dfs(1, 0);
    cout << ans[1] << endl;
    return 0;
}