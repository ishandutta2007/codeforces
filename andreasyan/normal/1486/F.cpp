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
const int N = 300005, L = 20;

ll ans;

int n, m;
vector<int> g[N];

int x0[N], y0[N];

int d[N];
int tin[N], tout[N], ti;
int p[N][L];
void dfs0(int x, int p0)
{
    d[x] = d[p0] + 1;
    tin[x] = ++ti;
    p[x][0] = p0;
    for (int i = 1; i < L; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs0(h, x);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int go(int x, int y)
{
    for (int i = L - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return x;
}

int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    for (int i = L - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

vector<pair<int, int> > v[N];

int q[N];

void dfs1(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        q[x] += q[h];
    }
}

int mp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &x0[i], &y0[i]);

    dfs0(1, 1);

    for (int i = 0; i < m; ++i)
    {
        int x = x0[i];
        int y = y0[i];
        int z = lca(x, y);

        int go1 = go(x, y);
        int go2 = go(y, x);
        if (go1 > go2)
            swap(go1, go2);
        v[z].push_back(m_p(go1, go2));

        q[x]++;
        q[y]++;
        q[z]-= 2;
    }
    dfs1(1, 1);
    for (int x = 1; x <= n; ++x)
        ans += (q[x] * 1LL * sz(v[x]));

    memset(q, 0, sizeof q);
    for (int i = 0; i < m; ++i)
    {
        int x = x0[i];
        int y = y0[i];
        int z = lca(x, y);

        int go1 = go(x, y);
        int go2 = go(y, x);
        if (go1 > go2)
            swap(go1, go2);

        q[x]++;
        q[y]++;
        q[go1]--;
        q[go2]--;
    }
    dfs1(1, 1);
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < v[x].size(); ++i)
        {
            mp[v[x][i].fi]++;
            mp[v[x][i].se]++;
        }
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p[x][0])
                continue;
            ans -= (q[h] * 1LL * mp[h]);
        }
        for (int i = 0; i < v[x].size(); ++i)
        {
            mp[v[x][i].fi]--;
            mp[v[x][i].se]--;
        }
    }

    map<pair<int, int>, int> mpp;
    for (int x = 1; x <= n; ++x)
    {
        int qq = 0;
        int q2 = 0;
        for (int i = 0; i < v[x].size(); ++i)
        {
            if (v[x][i].fi == v[x][i].se)
            {
                ++qq;
                continue;
            }
            mp[v[x][i].fi]++;
            mp[v[x][i].se]++;
            mpp[v[x][i]]++;

            if (v[x][i].fi == x || v[x][i].se == x)
                ++q2;
        }

        ll pans = 0;
        for (int i = 0; i < v[x].size(); ++i)
        {
            if (v[x][i].fi == v[x][i].se)
                continue;
            pans += (sz(v[x]) - qq);
            pans -= mp[v[x][i].fi];
            pans -= mp[v[x][i].se];
            pans += mpp[v[x][i]];
            if (v[x][i].fi == x || v[x][i].se == x)
                pans += (q2 - mpp[v[x][i]]);
        }
        pans += (qq * 1LL * (qq - 1));
        ans += (qq * 1LL * (sz(v[x]) - qq));
        ans += (pans / 2);

        for (int i = 0; i < v[x].size(); ++i)
        {
            if (v[x][i].fi == v[x][i].se)
                continue;
            mp[v[x][i].fi]--;
            mp[v[x][i].se]--;
        }
        mpp.clear();
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}