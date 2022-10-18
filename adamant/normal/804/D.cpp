#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;

const int maxn = 1e5 + 42;
vector<int> g[maxn];
int comp[maxn], mxd[maxn], mxu[maxn], sz[maxn];

void dfs(int v, int c)
{
    if(comp[v])
        return;
    comp[v] = c;
    sz[v] = 1;
    for(auto u: g[v])
        if(!comp[u])
        {
            dfs(u, c);
            sz[v] += sz[u];
            mxd[v] = max(mxd[v], mxd[u] + 1);
        }
}

vector<int> lens[maxn], sm[maxn];

void dfs2(int v, int p)
{
    multiset<int> pt = {mxu[v]};
    for(auto u: g[v])
        if(u != p)
            pt.insert(1 + mxd[u]);
    for(auto u: g[v])
        if(u != p)
        {
            pt.erase(pt.lower_bound(1 + mxd[u]));
            //cout << "from " << v << " to " << u << "\n";
            //for(auto it: pt)
            //    cout << it << ' ';
            //cout << endl;
            mxu[u] = 1 + *prev(end(pt));
            pt.insert(1 + mxd[u]);
            dfs2(u, v);
        }
    int cur = max(mxd[v], mxu[v]);
    while(cur >= lens[comp[v]].size())
        lens[comp[v]].push_back(0);
    while(cur >= sm[comp[v]].size())
        sm[comp[v]].push_back(0);
    lens[comp[v]][cur] += 1;
    sm[comp[v]][cur] += cur;
    //cout << v << ' ' << mxd[v] << ' ' << mxu[v] << endl;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        dfs(i, i);
    for(int i = 1; i <= n; i++)
        if(i == comp[i])
        {
            dfs2(i, i);
            for(int j = 1; j < lens[i].size(); j++)
            {
                sm[i][j] += sm[i][j - 1];
                lens[i][j] += lens[i][j - 1];
            }
        }
    map<int, double> ans[n + 1];
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        u = comp[u];
        v = comp[v];
        if(lens[u].size() > lens[v].size())
            swap(u, v);
        if(!ans[u][v])
        {
            if(u == v)
            {
                ans[u][v] = -1;
            }
            else
            {
                double cur = 0;
                int di = lens[v].size() - 1;
                //cout << lens[v].size() << ' ' << di << endl;
                for(int i = 0; i < lens[u].size(); i++)
                {
                    // i + j + 1 < di
                    int ls = (di - i - 2 < 0 ? 0 : lens[v][di - i - 2]);
                    int lsm = (di - i - 2 < 0 ? 0 : sm[v][di - i - 2]);
                    //cout << i << ' ' << (lens[u][i] - (i == 0 ? 0 : lens[u][i - 1])) << ' ' << ls << ' ' << lsm << ' ' << sz[v] << ' ' << sm[v][di] << endl;
                    cur += 1. * (lens[u][i] - (i == 0 ? 0 : lens[u][i - 1])) / sz[u] * (di * ls + (i + 1) * (sz[v] - ls) + sm[v][di] - lsm) / sz[v];
                }
                ans[u][v] = cur;
            }
        }
        cout << fixed << setprecision(8) << ans[u][v] << endl;
    }


}