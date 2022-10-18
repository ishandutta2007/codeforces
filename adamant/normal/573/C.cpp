#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42;
vector<int> g[maxn];
set<int> q;
int dist[maxn], pr[maxn];

int dfs(int v, int d = 1, int p = 0)
{
    pr[v] = p;
    dist[v] = d;
    int ret = q.count(v) * v;
    for(auto u: g[v])
        if(dist[u] == 0)
        {
            int t = dfs(u, d + 1, v);
            if(dist[t] > dist[ret])
                ret = t;
        }
    return ret;
}

vector<int> d[maxn];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> gg[n + 1];
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        gg[u].insert(v);
        gg[v].insert(u);
    }
    bool rep = 1;
    while(rep)
    {
        rep = 0;
        for(int i = 1; i <= n; i++)
            if(gg[i].size() == 2)
            {
                int v = *gg[i].begin();
                int u = *++gg[i].begin();
                if(gg[u].size() > 2 && gg[v].size() > 2)
                    continue;
                gg[v].insert(u);
                gg[v].erase(i);
                gg[u].insert(v);
                gg[u].erase(i);
                gg[i].clear();
                rep = 1;
            }
    }
    for(int v = 1; v <= n; v++)
        for(auto u: gg[v])
            g[v].push_back(u);
    for(int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < g[i].size(); j++)
                cnt += g[g[i][j]].size() == 1;
            if(g[i].size() && cnt + 1 != g[i].size() || g[i].size() > 3)
                q.insert(i);
        }
    if(q.empty())
    {
        cout << "Yes";
        return 0;
    }
    int A = dfs(*q.begin());
    memset(dist, 0, sizeof(dist));
    dfs(A);
    memset(dist, 0, sizeof(dist));
    for(auto v: q)
    {
        int u = v;
        while(!dist[u])
        {
            dist[u] = 1;
            d[pr[u]].push_back(0);
            u = pr[u];
        }
    }
    for(int v = 1; v <= n; v++)
        if(d[v].size() > 1)
            {
                cout << "No\n";
                return 0;
            }
    cout << "Yes\n";
	return 0;
}