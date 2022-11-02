#include <bits/stdc++.h>

using namespace std;

vector<int> g[200000];
bool used[200000] = {};

bool dfs(int v)
{
    used[v] = true;
    bool k = true;
    if (g[v].size() != 2)
        k = false;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (!used[g[v][i]])
            k = (k & dfs(g[v][i]));
    }
    return k;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for (int v = 0; v < n; v++)
    {
        if (!used[v])
            ans += dfs(v);
    }
    cout << ans;
}