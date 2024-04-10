#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 500005;

int n, k, m;
vector<pair<int, bool> > g[N];
pair<pair<int, int>, int> b[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int ck;
int c[N];
int q[N], d[N];
int p0[N];

void dfs0(int x, int p)
{
    p0[x] = p;
    c[x] = ck;
    q[x] = 1;
    d[x] = d[p] + 1;
    int maxu = -1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
        if (q[h] > maxu)
        {
            swap(g[x][i], g[x][0]);
            maxu = q[h];
        }
    }
}

int tin[N], tout[N], ti;
int rtin[N];
int f[N];

void dfs1(int x, int p)
{
    tin[x] = ++ti;
    rtin[ti] = x;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        if (i == 0)
        {
            f[h] = f[x];
        }
        else
        {
            f[h] = h;
        }
        dfs1(h, x);
    }
    tout[x] = ti;
}

int t[N * 4];

void ubd0(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = 1;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd0(tl, m, x, pos * 2);
    else
        ubd0(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

void dfs2(int x, int p, bool z)
{
    if (z)
        ubd0(1, n, tin[x], 1);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        dfs2(h, x, g[x][i].se);
    }
}

void shi(int pos)
{
    if (t[pos] == 0)
    {
        t[pos * 2] = t[pos * 2 + 1] = 0;
    }
}

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (t[pos] == 0)
        return;
    if (tl == l && tr == r)
    {
        t[pos] = 0;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (t[pos] == 0)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

ll ans;
void pro(int x, int y, int z)
{
    while (1)
    {
        if (f[x] == f[y])
            break;
        if (d[f[x]] < d[f[y]])
        {
            swap(x, y);
        }
        ans += qry(1, n, tin[f[x]], tin[x], 1) * 1LL * z;
        ubd(1, n, tin[f[x]], tin[x], 1);
        x = p0[f[x]];
    }
    if (d[x] < d[y])
        swap(x, y);
    ans += qry(1, n, tin[y] + 1, tin[x], 1) * 1LL * z;
    ubd(1, n, tin[y] + 1, tin[x], 1);
}

void solv()
{
    scanf("%d%d%d", &n, &k, &m);
    for (int x = 1; x <= n; ++x)
        p[x] = x;
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(m_p(y, true));
        g[y].push_back(m_p(x, true));
        kpc(x, y);
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (fi(x) != fi(y))
        {
            g[x].push_back(m_p(y, false));
            g[y].push_back(m_p(x, false));
            kpc(x, y);
        }
        b[i] = m_p(m_p(x, y), z);
    }

    dfs0(1, 1);
    f[1] = 1;
    dfs1(1, 1);
    dfs2(1, 1, false);

    for (int i = 0; i < m; ++i)
    {
        int x = b[i].fi.fi;
        int y = b[i].fi.se;
        int z = b[i].se;
        pro(x, y, z);
    }

    if (t[1])
        printf("-1\n");
    else
        printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}