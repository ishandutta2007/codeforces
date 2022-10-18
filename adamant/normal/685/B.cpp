#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 42;
vector<int> g[maxn];
int par[maxn];
int ans[maxn];
int sz[maxn], mx[maxn];



void dfs(int v)
{
    sz[v]++;
    for(auto u: g[v])
    {
        dfs(u);
        sz[v] += sz[u];
        mx[v] = max(mx[v], sz[u]);
    }
}

void dfs(int v, set<pair<int, int>> &pars)
{
    pars.insert({sz[v], v});
    for(auto u: g[v])
        dfs(u, pars);
    for(auto it = pars.lower_bound({2 * mx[v], 0}); it != pars.lower_bound({2 * sz[v] + 1, 0}); it++)
        ans[it->second] = v;
    pars.erase({sz[v], v});
}

signed main()
{
    memset(ans, -1, sizeof(ans));
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    dfs(0);
    set<pair<int, int>> lol;
    dfs(0, lol);
    while(q--)
    {
        int v;
        cin >> v;
        cout << ans[v - 1] + 1 << "\n";
    }
	return 0;
}