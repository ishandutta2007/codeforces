#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42;
vector<int> g[maxn];
int color[maxn];

void fail()
{
    cout << -1 << "\n";
    exit(0);
}

void dfs(int v, int cl = 1)
{
    if(color[v])
    {
        if(color[v] == cl)
            return;
        fail();
    }
    color[v] = cl;
    for(auto u: g[v])
        dfs(u, (cl == 1) ? 2 : 1);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    for(int i = 0; i < n; i++)
        if(!color[i])
            dfs(i, 1);
    vector<int> t[3];
    for(int i = 0; i < n; i++)
        t[color[i]].push_back(i);
    for(int i = 1; i <= 2; i++){
    cout << t[i].size() << "\n";
    for(auto it: t[i])
        cout << it + 1 << ' ';
    cout << "\n";}
	return 0;
}