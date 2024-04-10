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

int n1, n2, m, qq;
vector<int> g[N], rg[N];
map<pair<int, int>, int> mp;

int u[N], ru[N];
bool c[N];
vector<int> v;
bool dfs(int x)
{
    if (c[x])
        return false;
    c[x] = true;
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!u[h] || dfs(u[h]))
        {
            u[h] = x;
            ru[x] = h;
            return true;
        }
    }
    return false;
}

bool c1[N];
void dfs1(int x)
{
    if (c1[x])
        return;
    c1[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (u[h])
            dfs1(u[h]);
    }
}

bool c2[N];
void dfs2(int x)
{
    if (c2[x])
        return;
    c2[x] = true;
    for (int i = 0; i < rg[x].size(); ++i)
    {
        int h = rg[x][i];
        if (ru[h])
            dfs2(ru[h]);
    }
}

void solv()
{
    cin >> n1 >> n2 >> m >> qq;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
        mp[m_p(x, y)] = i;
    }

    for (int x = 1; x <= n1; ++x)
    {
        dfs(x);
        while (!v.empty())
        {
            c[v.back()] = false;
            v.pop_back();
        }
    }

    for (int y = 1; y <= n2; ++y)
    {
        if (u[y])
            c[u[y]] = true;
    }
    for (int x = 1; x <= n1; ++x)
    {
        if (!c[x])
            dfs1(x);
    }
    for (int y = 1; y <= n2; ++y)
    {
        if (!u[y])
            dfs2(y);
    }

    vector<pair<int, int> > v1, v2;
    ll s = 0;
    for (int y = 1; y <= n2; ++y)
    {
        if (u[y])
        {
            s += mp[m_p(u[y], y)];
            if (!c2[y] || !c1[u[y]])
                v1.push_back(m_p(u[y], y));
            else
                v2.push_back(m_p(u[y], y));
        }
    }

    assert(v2.empty());
    while (qq--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            if (!v1.empty())
            {
                cout << "1" << endl;
                if (!c1[v1.back().fi])
                {
                    cout << v1.back().fi << endl;
                }
                else
                {
                    assert(!c2[v1.back().se]);
                    cout << -v1.back().se << endl;
                }
                s -= mp[m_p(v1.back().fi, v1.back().se)];
                v1.pop_back();
                cout << s << endl;
            }
            else
            {
                cout << "2" << endl;
                cout << v2.back().fi << ' ' << -v2.back().se << endl;
                s -= mp[m_p(v2.back().fi, v2.back().se)];
                v2.pop_back();
                cout << s << endl;
            }
        }
        else
        {
            cout << sz(v1) + sz(v2) << endl;
            for (int i = 0; i < sz(v1); ++i)
                cout << mp[m_p(v1[i].fi, v1[i].se)] << ' ';
            for (int i = 0; i < sz(v2); ++i)
                cout << mp[m_p(v2[i].fi, v2[i].se)] << ' ';
            cout << endl;
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