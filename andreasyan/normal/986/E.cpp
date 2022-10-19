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
const int N = 100005, K = 10000007, M = 1000000007, m = 18;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int u[K];
int uu[K];
int ruu[N * 10];
void pre()
{
    u[1] = 1;
    int z = 0;
    for (int i = 2; i < K; ++i)
    {
        if (u[i])
            continue;
        uu[i] = ++z;
        ruu[z] = i;
        for (int j = i; j < K; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
}

int n;
vector<int> g[N];
int a[N];
int q;
pair<pair<int, int>, int> b[N];

int tin[N], tout[N], ti;
int p[N][m];
void dfs0(int x, int p0)
{
    tin[x] = ++ti;
    p[x][0] = p0;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs0(h, x);
    }
    tout[x] = ++ti;
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
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

int bb[N];

vector<pair<int, int> > v[N * 10];

int t[N * 2];
void ubd(int x, int y)
{
    while (x <= n * 2)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int l, int r)
{
    int ans = 0;
    while (r)
    {
        ans += t[r];
        r -= (r & (-r));
    }

    --l;
    while (l)
    {
        ans -= t[l];
        l -= (l & (-l));
    }

    return ans;
}

int ans[N];

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
        cin >> a[x];
    cin >> q;
    for (int i = 1; i <= q; ++i)
        cin >> b[i].fi.fi >> b[i].fi.se >> b[i].se;

    dfs0(1, 1);

    for (int i = 1; i <= q; ++i)
    {
        bb[i] = lca(b[i].fi.fi, b[i].fi.se);
        ans[i] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        vector<pair<int, int> > vv;
        while (x > 1)
        {
            if (vv.empty() || vv.back().fi != u[x])
                vv.push_back(m_p(u[x], 1));
            else
                vv.back().se++;
            x /= u[x];
        }

        for (int j = 0; j < sz(vv); ++j)
        {
            v[uu[vv[j].fi]].push_back(m_p(vv[j].se, i));
        }
    }

    for (int i = 1; i <= q; ++i)
    {
        int x = b[i].se;
        vector<pair<int, int> > vv;
        while (x > 1)
        {
            if (vv.empty() || vv.back().fi != u[x])
                vv.push_back(m_p(u[x], 1));
            else
                vv.back().se++;
            x /= u[x];
        }

        for (int j = 0; j < sz(vv); ++j)
        {
            v[uu[vv[j].fi]].push_back(m_p(vv[j].se, -i));
        }
    }

    for (int i = 1; i < N * 10; ++i)
    {
        if (v[i].empty())
            continue;

        sort(all(v[i]));

        for (int j = 0; j < sz(v[i]); ++j)
        {
            if (v[i][j].se > 0)
            {
                ubd(tin[v[i][j].se], v[i][j].fi);
                ubd(tout[v[i][j].se], -v[i][j].fi);
            }
            else
            {
                v[i][j].se *= -1;

                int q = qry(tin[bb[v[i][j].se]], tin[b[v[i][j].se].fi.fi]) +
                        qry(tin[bb[v[i][j].se]] + 1, tin[b[v[i][j].se].fi.se]);
                ans[v[i][j].se] = (ans[v[i][j].se] * 1LL * ast(ruu[i], q)) % M;

                v[i][j].se *= -1;
            }
        }
        for (int j = 0; j < sz(v[i]); ++j)
        {
            if (v[i][j].se > 0)
            {
                ubd(tin[v[i][j].se], -v[i][j].fi);
                ubd(tout[v[i][j].se], v[i][j].fi);
            }
        }

        reverse(all(v[i]));

        for (int j = 0; j < sz(v[i]); ++j)
        {
            if (v[i][j].se > 0)
            {
                ubd(tin[v[i][j].se], 1);
                ubd(tout[v[i][j].se], -1);
            }
            else
            {
                v[i][j].se *= -1;

                int q = qry(tin[bb[v[i][j].se]], tin[b[v[i][j].se].fi.fi]) +
                        qry(tin[bb[v[i][j].se]] + 1, tin[b[v[i][j].se].fi.se]);
                q *= v[i][j].fi;
                ans[v[i][j].se] = (ans[v[i][j].se] * 1LL * ast(ruu[i], q)) % M;

                v[i][j].se *= -1;
            }
        }
        for (int j = 0; j < sz(v[i]); ++j)
        {
            if (v[i][j].se > 0)
            {
                ubd(tin[v[i][j].se], -1);
                ubd(tout[v[i][j].se], 1);
            }
        }
    }

    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}