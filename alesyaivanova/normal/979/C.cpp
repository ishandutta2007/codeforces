#include <bits/stdc++.h>

using namespace std;

vector<int> g[300000];
int n, p, x, y;

int dfs1(int v, int pr)
{
    if (v == y)
    {
        p = pr;
        return -1;
    }
    int ans = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (to != pr)
        {
            int k = dfs1(to, v);
            if (k == -1)
                return -1;
            ans += k;
        }
    }
    return ans;
}

int dfs(int v, int pr)
{
    int ans = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (to != pr)
            ans += dfs(to, v);
    }
    return ans;
}

int main()
{
    cin >> n >> x >> y;
    x--;
    y--;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int u = 1;
    for (int i = 0; i < (int)g[x].size(); i++)
    {
        int to = g[x][i];
        int k = dfs1(to, x);
        if (k != -1)
            u += k;
    }
    int q = dfs(y, p);
    long long answer = n * 1ll * (n - 1) - u * 1ll * q;
    cout << answer;
}