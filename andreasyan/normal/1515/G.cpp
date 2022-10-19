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

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n, m;
vector<pair<int, int> > g[N];
vector<pair<int, int> > rg[N];

int c[N];

vector<int> v;
void dfs0(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (!c[h])
            dfs0(h);
    }
    v.push_back(x);
}

int k;
void dfs1(int x)
{
    c[x] = k;
    for (int i = 0; i < rg[x].size(); ++i)
    {
        int h = rg[x][i].fi;
        if (!c[h])
            dfs1(h);
    }
}

bool c2[N];
ll d2[N];
void dfs2(int x)
{
    c2[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (c[x] != c[h])
            continue;
        if (!c2[h])
        {
            d2[h] = d2[x] + g[x][i].se;
            dfs2(h);
        }
    }
}

bool c3[N];
ll d3[N];
void dfs3(int x)
{
    c3[x] = true;
    for (int i = 0; i < rg[x].size(); ++i)
    {
        int h = rg[x][i].fi;
        if (c[x] != c[h])
            continue;
        if (!c3[h])
        {
            d3[h] = d3[x] + rg[x][i].se;
            dfs3(h);
        }
    }
}

ll gg[N];

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(m_p(y, z));
        rg[y].push_back(m_p(x, z));
    }

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
            dfs0(x);
    }
    reverse(all(v));
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; ++i)
    {
        int x = v[i];
        if (!c[x])
        {
            ++k;
            dfs1(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (!c2[x])
        {
            dfs2(x);
        }
        if (!c3[x])
        {
            dfs3(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            int y = g[x][i].fi;
            if (c[x] == c[y])
            {
                ll d = d2[x] + g[x][i].se + d3[y];
                gg[c[x]] = gcd(gg[c[x]], d);
            }
        }
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        ll x, s, t;
        cin >> x >> s >> t;
        x = gg[c[x]];
        s = t - s;

        x = gcd(x, t);
        x /= gcd(x, s);

        if (gcd(x, t) == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
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