#include <bits/stdc++.h>

using namespace std;

#define int int64_t

map<vector<int>, int> hasher;

int get_hash(vector<int> a)
{
    if(hasher[a] == 0)
        hasher[a] = hasher.size();
    return hasher[a];
}

const int maxn = 4e5;
vector<int> G[maxn];
int color[maxn];

int dfs(int v, int p)
{
    for(auto u: G[v])
        if(u != p)
        {
            color[u] = color[v] + 1;
            dfs(u, v);
        }

}

void fail()
{
    cout << "NO" << endl;
    exit(0);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int in_comp[n];
    for(int i = 0; i < n; i++)
    {
        g[i].push_back(i);
        sort(begin(g[i]), end(g[i]));
        in_comp[i] = get_hash(g[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(auto u: g[i])
            if(in_comp[i] != in_comp[u])
            {
                G[in_comp[i]].push_back(in_comp[u]);
                G[in_comp[u]].push_back(in_comp[i]);
            }
    }
    int t = -1;
    for(int i = 1; i <= hasher.size(); i++)
    {
        sort(begin(G[i]), end(G[i]));
        G[i].erase(unique(begin(G[i]), end(G[i])), end(G[i]));
        if(G[i].size() <= 1)
            t = i;
        if(G[i].size() > 2)
            fail();
    }
    if(t == -1)
        fail();
    dfs(t, t);
    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
        cout << color[in_comp[i]] + 1 << ' ';
}