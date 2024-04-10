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
const int N = 200005, m = 20;

int n, qq;
int e[N];
vector<pair<int, pair<int, int> > > b;
vector<pair<int, int> > g[N];

vector<pair<int, pair<int, int> > > qv;

int p[N][m];
int maxu[N][m];
int tin[N], tout[N], ti;
void dfs(int x, int p0, int k0)
{
    tin[x] = ++ti;
    p[x][0] = p0;
    maxu[x][0] = k0;
    for (int i = 1; i < m; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
        maxu[x][i] = max(maxu[x][i - 1], maxu[p[x][i - 1]][i - 1]);
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p0)
            continue;
        dfs(h, x, g[x][i].se);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int go(int x, int y)
{
    if (isp(x, y))
        return 0;
    int ans = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
        {
            ans = max(ans, maxu[x][i]);
            x = p[x][i];
        }
    }
    ans = max(ans, maxu[x][0]);
    return ans;
}

int qry(int x, int y)
{
    return max(go(x, y), go(y, x));
}

int p0[N];
int maxx[N];
int maxd[N];

int fi(int x)
{
    if (x == p0[x])
        return x;
    return p0[x] = fi(p0[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);

    if (e[maxx[x]] > e[maxx[y]])
        swap(x, y);

    if (e[maxx[x]] < e[maxx[y]])
    {
        p0[x] = y;
    }
    else if (e[maxx[x]] == e[maxx[y]])
    {
        p0[x] = y;
        maxd[y] = max(maxd[y], max(maxd[x], qry(maxx[x], maxx[y])));
    }
}

int ans1[N], ans2[N];

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> e[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, c, t;
        cin >> x >> y >> c >> t;
        g[x].push_back(m_p(y, t));
        g[y].push_back(m_p(x, t));
        b.push_back(m_p(c, m_p(x, y)));
    }

    for (int i = 0; i < qq; ++i)
    {
        int c, x;
        cin >> c >> x;
        qv.push_back(m_p(c, m_p(x, i)));
    }

    dfs(1, 1, 0);

    sort(all(b));
    reverse(all(b));
    sort(all(qv));
    reverse(all(qv));

    for (int i = 1; i <= n; ++i)
    {
        p0[i] = i;
        maxx[i] = i;
        maxd[i] = 0;
    }

    int j = 0;
    for (int i = 0; i < sz(qv); ++i)
    {
        while (j < sz(b) && b[j].fi >= qv[i].fi)
        {
            kpc(b[j].se.fi, b[j].se.se);
            ++j;
        }
        int x = qv[i].se.fi;
        ans1[qv[i].se.se] = e[maxx[fi(x)]];
        ans2[qv[i].se.se] = max(maxd[fi(x)], qry(x, maxx[fi(x)]));
    }

    for (int i = 0; i < qq; ++i)
        cout << ans1[i] << ' ' << ans2[i] << "\n";
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