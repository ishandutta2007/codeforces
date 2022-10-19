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
const int N = 210005, N0 = 100005;

int n, m;
int s[N];
int u1[N], u2[N];

vector<int> g[N], rg[N];

vector<int> v;

int c[N];
void dfs0(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
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
        int h = rg[x][i];
        if (!c[h])
            dfs1(h);
    }
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i <= m; ++i)
    {
        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            if (u1[x] == 0)
                u1[x] = i;
            else
                u2[x] = i;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 0)
        {
            g[N0 - u1[i]].push_back(N0 + u2[i]);
            g[N0 + u1[i]].push_back(N0 - u2[i]);
            g[N0 - u2[i]].push_back(N0 + u1[i]);
            g[N0 + u2[i]].push_back(N0 - u1[i]);
        }
        else
        {
            g[N0 + u1[i]].push_back(N0 + u2[i]);
            g[N0 + u2[i]].push_back(N0 + u1[i]);
            g[N0 - u1[i]].push_back(N0 - u2[i]);
            g[N0 - u2[i]].push_back(N0 - u1[i]);
        }
    }

    for (int x = 1; x <= m; ++x)
    {
        for (int i = 0; i < g[N0 + x].size(); ++i)
        {
            int y = g[N0 + x][i];
            rg[y].push_back(N0 + x);
        }
        for (int i = 0; i < g[N0 - x].size(); ++i)
        {
            int y = g[N0 - x][i];
            rg[y].push_back(N0 - x);
        }
    }

    for (int x = 1; x <= m; ++x)
    {
        if (!c[N0 + x])
            dfs0(N0 + x);
        if (!c[N0 - x])
            dfs0(N0 - x);
    }
    reverse(all(v));

    memset(c, 0, sizeof c);
    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i];
        if (!c[x])
        {
            ++k;
            dfs1(x);
        }
    }

    for (int x = 1; x <= m; ++x)
    {
        if (c[N0 + x] == c[N0 - x])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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