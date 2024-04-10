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
const int N = 200005, M = 998244353;

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

int u[N];
vector<pair<int, int> > v[N];
void pre()
{
    u[1] = 1;
    for (int i = 1; i < N; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
    for (int i = 1; i < N; ++i)
    {
        int x = i;
        v[i].push_back(m_p(u[x], 0));
        while (x > 1)
        {
            if (v[i].back().fi != u[x])
                v[i].push_back(m_p(u[x], 0));
            v[i].back().se++;
            x /= u[x];
        }
    }
}

int n;
vector<pair<int, pair<int, int> > > g[N];

int q[N];
int maxu[N];
void dfs(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        int a = g[x][i].se.fi;
        int b = g[x][i].se.se;
        if (h == p)
            continue;
        for (int j = 0; j < sz(v[a]); ++j)
        {
            q[v[a][j].fi] += v[a][j].se;
        }
        for (int j = 0; j < sz(v[b]); ++j)
        {
            q[v[b][j].fi] -= v[b][j].se;
        }
        for (int j = 0; j < sz(v[a]); ++j)
        {
            maxu[v[a][j].fi] = max(maxu[v[a][j].fi], q[v[a][j].fi]);
        }
        dfs(h, x);
        for (int j = 0; j < sz(v[a]); ++j)
        {
            q[v[a][j].fi] -= v[a][j].se;
        }
        for (int j = 0; j < sz(v[b]); ++j)
        {
            q[v[b][j].fi] += v[b][j].se;
        }
    }
}

int ans;
void dfs1(int x, int p, int yans)
{
    ans = (ans + yans) % M;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        int a = g[x][i].se.fi;
        int b = g[x][i].se.se;
        if (h == p)
            continue;
        int cans = yans;
        yans = (yans * 1LL * b) % M;
        yans = (yans * 1LL * ast(a, M - 2)) % M;
        dfs1(h, x, yans);
        yans = cans;
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        g[x].push_back(m_p(y, m_p(a, b)));
        g[y].push_back(m_p(x, m_p(b, a)));
    }

    dfs(1, 1);

    vector<int> vv;
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            int a = g[x][i].se.fi;
            for (int j = 0; j < sz(v[a]); ++j)
            {
                vv.push_back(v[a][j].fi);
            }
        }
    }
    sort(all(vv));

    int ans1 = 1;
    for (int i = 0; i < sz(vv); ++i)
    {
        if (!i || vv[i] != vv[i - 1])
        {
            ans1 = (ans1 * 1LL * ast(vv[i], maxu[vv[i]])) % M;
            maxu[vv[i]] = 0;
        }
    }

    ans = 0;
    dfs1(1, 1, ans1);

    cout << ans << "\n";
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}