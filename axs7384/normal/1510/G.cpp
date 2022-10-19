#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

int kase, n, k, u, v;
int vis[maxn];
vector<int> g[maxn], ans, temp;

int cnt = 0;
void dfs (int u, int t)
{
    if (u == t)
    {
        vis[u] = 1;
        return ;
    }
    for (auto v : g[u])
    {
        dfs (v, t);
        vis[u] |= vis[v];
    }
}
void dfs2 (int u)
{
    temp.push_back (u);
    cnt++;
    for (auto v : g[u])
    {
        if (vis[v] || cnt == k) continue;
        dfs2 (v);
        temp.push_back(u);
    }
}
void dfs1 (int u)
{
    temp.push_back(u);
    for (auto v : g[u])
    {
        if (vis[v] || cnt == k) continue;
        dfs2 (v);
        temp.push_back (u);
    }
    for (auto v : g[u]) if (vis[v]) dfs1 (v);
}

int main()
{
    scanf ("%d", &kase);
    while (kase--)
    {
        scanf ("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) g[i].clear();
        ans.clear();
        for (int i = 2; i <= n; i++)
        {
            scanf ("%d", &u);
            g[u].push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            cnt = 0;
            memset (vis, 0, sizeof vis);
            dfs (1, i);
            for (int j = 1; j <= n; j++) cnt += vis[j];
            if (cnt > k) continue;
            temp.clear();
            dfs1 (1);
            if (ans.size() == 0 || ans.size() > temp.size())
                ans = temp;
        }
        printf ("%d\n", (int)ans.size() - 1);
        for (auto it : ans) printf ("%d ", it);
        puts ("");
    }
    return 0;
}