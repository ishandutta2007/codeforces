#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1500 + 7;
int sz[N];
int x[N], y[N];
int res[N];
vector <int> g[N];
int s;

void clc(int v, int pr)
{
    sz[v] = 1;
    for (auto to : g[v])
    {
        if (to != pr)
        {
            clc(to, v);
            sz[v] += sz[to];
        }
    }
    sort(g[v].begin(), g[v].end(), [] (int a, int b)
    {
        return sz[a] < sz[b];
    });
}

void dfs(int v, int pr, vector <int> &pts)
{
    sort(pts.begin(), pts.end(), [] (int a, int b)
    {
        return (x[a] != x[b] ? x[a] < x[b] : y[a] < y[b]);
    });
    s = pts[0];
    res[s] = v;
    sort(pts.begin() + 1, pts.end(), [] (int a, int b)
    {
        int x1 = x[a] - x[s];
        int y1 = y[a] - y[s];
        int x2 = x[b] - x[s];
        int y2 = y[b] - y[s];
        return (x1 * (ll) y2 - x2 * (ll) y1 < 0);
    });
    int z = 1;
    for (auto to : g[v])
    {
        if (to != pr)
        {
            vector <int> d;
            for (int cur = z; cur < z + sz[to]; cur++)
            {
                d.push_back(pts[cur]);
            }
            dfs(to, v, d);
            z += sz[to];
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> d;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        d.push_back(i);
    }
    clc(1, -1);
    dfs(1, -1, d);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << ' ';
    }
}