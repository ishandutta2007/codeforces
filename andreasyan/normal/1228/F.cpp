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

int en, n;
vector<int> g[N];

int d[N];
void dfs0(int x, int p)
{
    d[x] = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        d[x] = max(d[x], d[h] + 1);
    }
}

void dfs1(int x, int p)
{
    d[x] = -N;
    vector<int> u;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        u.push_back(d[h]);
    }

    if (u.empty())
        d[x] = 0;
    else if (sz(u) == 2 && u[0] == u[1])
        d[x] = u[0] + 1;
}

set<int> ans;
void dfs2(int x, int p, int s)
{
    vector<int> u;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        u.push_back(d[h]);
    }
    sort(all(u));

    if (sz(u) == 3)
    {
        if (u[0] == s - 2 && u[1] == s - 2 && u[2] == s - 1)
        {
            ans.insert(x);
            return;
        }
        return;
    }
    if (sz(u) == 2)
    {
        if (u[0] == -N && u[1] == s - 1)
        {
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                if (h == p)
                    continue;
                if (d[h] == -N)
                {
                    dfs2(h, x, s - 1);
                    return;
                }
            }
        }
        return;
    }
    if (sz(u) == 1)
    {
        if (s == 1 && u[0] == 0)
        {
            ans.insert(x);
            return;
        }
    }
}

void solv()
{
    cin >> en;
    n = (1 << en) - 2;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs0(1, 1);
    int x = 1;
    while (1)
    {
        int sx = x;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (d[h] == d[x] - 1)
            {
                x = h;
                break;
            }
        }
        if (x == sx)
            break;
    }
    dfs0(x, x);
    vector<int> v;
    while (1)
    {
        v.push_back(x);
        int sx = x;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (d[h] == d[x] - 1)
            {
                x = h;
                break;
            }
        }
        if (x == sx)
            break;
    }

    for (int i = max(0, sz(v) / 2 - 2); i <= min(sz(v) - 1, sz(v) / 2 + 2); ++i)
    {
        int r = v[i];
        dfs1(r, r);
        dfs2(r, r, en - 1);
    }

    cout << sz(ans) << "\n";
    for (auto it = ans.begin(); it != ans.end(); ++it)
        cout << *it << ' ';
    cout << "\n";
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