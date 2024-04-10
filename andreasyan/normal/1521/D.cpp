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
const int N = 100005;

int n;
vector<int> g[N];

int dp[N][2];

void dfs(int x, int p)
{
    int s = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        s += (1 + dp[h][0]);
    }

    dp[x][1] = s;

    vector<pair<int, int> > v;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        v.push_back(m_p(-(1 + dp[h][0]) + dp[h][1], h));
        dp[x][1] = min(dp[x][1], s - (1 + dp[h][0]) + dp[h][1]);
    }

    sort(all(v));
    dp[x][0] = dp[x][1];
    if (sz(v) >= 2)
        dp[x][0] = min(dp[x][0], s + v[0].fi + v[1].fi);
}

vector<pair<int, int> > han;
vector<int> gg[N];
void dfs1(int x, int p, int z)
{
    int s = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        s += (1 + dp[h][0]);
    }

    if (z == 0 && dp[x][0] == dp[x][1])
        z = 1;

    if (z == 1)
    {
        if (dp[x][z] == s)
        {
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                if (h == p)
                    continue;
                han.push_back(m_p(x, h));
                dfs1(h, x, 0);
            }
            return;
        }
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            if (dp[x][1] == s - (1 + dp[h][0]) + dp[h][1])
            {
                gg[x].push_back(h);
                gg[h].push_back(x);
                dfs1(h, x, 1);
                for (int j = 0; j < g[x].size(); ++j)
                {
                    int h = g[x][j];
                    if (h == p)
                        continue;
                    if (i == j)
                        continue;
                    han.push_back(m_p(x, h));
                    dfs1(h, x, 0);
                }
                return;
            }
        }
    }
    else
    {
        vector<pair<int, int> > v;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            v.push_back(m_p(-(1 + dp[h][0]) + dp[h][1], h));
        }
        sort(all(v));
        gg[v[0].se].push_back(x);
        gg[x].push_back(v[0].se);
        dfs1(v[0].se, x, 1);
        gg[v[1].se].push_back(x);
        gg[x].push_back(v[1].se);
        dfs1(v[1].se, x, 1);
        for (int i = 2; i < v.size(); ++i)
        {
            han.push_back(m_p(v[i].se, x));
            dfs1(v[i].se, x, 0);
        }
    }
}

void solv()
{
    cin >> n;
    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        gg[x].clear();
    }
    han.clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);
    dfs1(1, 1, 0);
    assert(sz(han) == dp[1][0]);

    vector<pair<int, int> > ends;
    for (int x = 1; x <= n; ++x)
    {
        if (gg[x].empty())
        {
            ends.push_back(m_p(x, x));
        }
        else if (gg[x].size() == 1)
        {
            int p = x;
            int y = x;
            while (1)
            {
                for (int i = 0; i < gg[y].size(); ++i)
                {
                    int h = gg[y][i];
                    if (h == p)
                        continue;
                    p = y;
                    y = h;
                    break;
                }
                if (gg[y].size() == 1)
                    break;
            }
            if (x < y)
                ends.push_back(m_p(x, y));
        }
    }

    assert(sz(han) == sz(ends) - 1);

    cout << sz(han) << "\n";
    for (int i = 0; i < sz(han); ++i)
    {
        cout << han[i].fi << ' ' << han[i].se << ' ' << ends[i].se << ' ' << ends[i + 1].fi << "\n";
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}