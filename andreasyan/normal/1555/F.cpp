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

int n, m;
int x[N], y[N], z[N];

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

bool ck[N];
vector<pair<int, int> > g[N];

int d[N];
bool c[N];
void dfs0(int x, int p)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        d[h] = (d[x] ^ g[x][i].se);
        dfs0(h, x);
    }
}

int p0[N];
int q[N];
void dfs(int x, int p)
{
    p0[x] = p;
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
        {
            swap(g[x][i], g[x].back());
            break;
        }
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        dfs(h, x);
        q[x] += q[h];
        if (q[h] > q[0])
            swap(g[x][i], g[x][0]);
    }
}

int tin[N], tout[N], ti;
int f[N];
void dfs1(int x, int p)
{
    tin[x] = ++ti;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        if (i == 0)
            f[h] = f[x];
        else
            f[h] = h;
        dfs1(h, x);
    }
    tout[x] = ti;
}

bool t[N * 4];
bool laz[N * 4];
void shi(int pos)
{
    if (!laz[pos])
        return;
    t[pos * 2] = laz[pos * 2] = t[pos * 2 + 1] = laz[pos * 2 + 1] = true;
    laz[pos] = false;
}

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] = true;
        laz[pos] = true;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    t[pos] = (t[pos * 2] || t[pos * 2 + 1]);
}

bool qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return false;
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) ||
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

bool qryy(int x, int y)
{
    while (f[x] != f[y])
    {
        if (tin[x] < tin[y])
            swap(x, y);
        if (qry(1, n, tin[f[x]], tin[x], 1))
            return true;
        x = p0[f[x]];
    }
    if (tin[x] < tin[y])
        swap(x, y);
    return qry(1, n, tin[y] + 1, tin[x], 1);
}

void ubdd(int x, int y)
{
    while (f[x] != f[y])
    {
        if (tin[x] < tin[y])
            swap(x, y);
        ubd(1, n, tin[f[x]], tin[x], 1);
        x = p0[f[x]];
    }
    if (tin[x] < tin[y])
        swap(x, y);
    ubd(1, n, tin[y] + 1, tin[x], 1);
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
    }

    for (int i = 1; i <= m; ++i)
    {
        cin >> x[i] >> y[i] >> z[i];

        if (fi(x[i]) != fi(y[i]))
        {
            ck[i] = true;
            kpc(x[i], y[i]);
            g[x[i]].push_back(m_p(y[i], z[i]));
            g[y[i]].push_back(m_p(x[i], z[i]));
        }
    }

    vector<int> r;
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            dfs0(x, x);
            r.push_back(x);
        }
    }

    for (int i = 0; i < sz(r); ++i)
    {
        dfs(r[i], r[i]);
        f[r[i]] = r[i];
        dfs1(r[i], r[i]);
    }

    for (int i = 1; i <= m; ++i)
    {
        if (ck[i])
        {
            cout << "YES\n";
            continue;
        }
        if (x[i] == 2 && y[i] == 4 && z[i] == 0)
            cout << "";
        if ((d[x[i]] ^ d[y[i]] ^ z[i]) == 0)
        {
            cout << "NO\n";
            continue;
        }
        if (qryy(x[i], y[i]))
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            ubdd(x[i], y[i]);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}