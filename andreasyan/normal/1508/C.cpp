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
const int N = 200005;

bool so(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b)
{
    return a.se < b.se;
}

int n, m;
pair<pair<int, int>, int> b[N];
vector<int> g[N];

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

set<int> s;
void dfs(int x)
{
    s.erase(x);
    int i = 0;
    while (i < sz(g[x]))
    {
        if (s.empty())
            break;
        if (i == 0)
        {
            int h = *s.begin();
            if (h < g[x][i])
            {
                kpc(x, h);
                dfs(h);
            }
            else
                ++i;
        }
        else
        {
            auto it = s.upper_bound(g[x][i - 1]);
            int h = n + 10;
            if (it != s.end())
                h = *it;
            if (h < g[x][i])
            {
                kpc(x, h);
                dfs(h);
            }
            else
                ++i;
        }
    }
}

bool c[N];
bool dfs1(int x, int p)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (!c[h])
        {
            if (dfs1(h, x))
                return true;
        }
        else
            return true;
    }
    return false;
}

vector<bool> gg[N];
const int l = 20;
int tp[N][l];
int q[N];
int tin[N], tout[N], ti;
void dfs2(int x, int p0)
{
    tin[x] = ++ti;
    tp[x][0] = p0;
    for (int i = 1; i < l; ++i)
        tp[x][i] = tp[tp[x][i - 1]][i - 1];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        q[h] = q[x] + gg[x][i];
        dfs2(h, x);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    for (int i = l - 1; i >= 0; --i)
    {
        if (!isp(tp[x][i], y))
            x = tp[x][i];
    }
    return tp[x][0];
}

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i].fi.fi >> b[i].fi.se >> b[i].se;
    }
    sort(b, b + m, so);

    for (int i = 1; i <= n; ++i)
        p[i] = i;

    if (n > 700)
    {
        for (int i = 0; i < m; ++i)
        {
            g[b[i].fi.fi].push_back(b[i].fi.se);
            g[b[i].fi.se].push_back(b[i].fi.fi);
        }
        for (int x = 1; x <= n; ++x)
        {
            sort(all(g[x]));
            g[x].push_back(n + 1);
        }
        for (int x = 1; x <= n; ++x)
            s.insert(x);
        for (int x = 1; x <= n; ++x)
        {
            if (s.find(x) != s.end())
                dfs(x);
        }
        ll ans = 0;
        for (int i = 0; i < m; ++i)
        {
            int x = b[i].fi.fi;
            int y = b[i].fi.se;
            int z = b[i].se;
            if (fi(x) != fi(y))
            {
                ans += z;
                kpc(x, y);
            }
        }

        cout << ans << "\n";
        return;
    }

    set<pair<int, int> > ss;
    for (int i = 0; i < m; ++i)
        ss.insert(m_p(min(b[i].fi.fi, b[i].fi.se), max(b[i].fi.fi, b[i].fi.se)));
    vector<pair<int, int> > v;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = x + 1; y <= n; ++y)
        {
            if (ss.find(m_p(x, y)) == ss.end())
            {
                g[x].push_back(y);
                g[y].push_back(x);
                gg[x].push_back(true);
                gg[y].push_back(true);
                v.push_back(m_p(x, y));
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            if (dfs1(x, -1))
            {
                for (int i = 0; i < v.size(); ++i)
                    kpc(v[i].fi, v[i].se);
                ll ans = 0;
                for (int i = 0; i < m; ++i)
                {
                    int x = b[i].fi.fi;
                    int y = b[i].fi.se;
                    int z = b[i].se;
                    if (fi(x) != fi(y))
                    {
                        ans += z;
                        kpc(x, y);
                    }
                }
                cout << ans << "\n";
                return;
            }
        }
    }
    int xx = 0;
    for (int i = 0; i < m; ++i)
        xx ^= b[i].se;
    for (int i = 0; i < v.size(); ++i)
    {
        kpc(v[i].fi, v[i].se);
    }
    ll ans = xx;
    for (int i = 0; i < m; ++i)
    {
        int x = b[i].fi.fi;
        int y = b[i].fi.se;
        int z = b[i].se;
        if (fi(x) != fi(y))
        {
            ans += z;
            kpc(x, y);
            g[x].push_back(y);
            g[y].push_back(x);
            gg[x].push_back(false);
            gg[y].push_back(false);
        }
    }

    dfs2(1, 1);

    for (int i = 0; i < m; ++i)
    {
        int x = b[i].fi.fi;
        int y = b[i].fi.se;
        int z = b[i].se;
        if (q[x] + q[y] - 2 * q[lca(x, y)] > 0)
        {
            ans = min(ans, ans - xx + z);
            break;
        }
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}