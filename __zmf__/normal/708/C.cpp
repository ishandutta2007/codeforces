/*
    
    
    
    
    
    
    
    
    
    
    
    
                                      ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int sum = 0, nega = 1;
    char ch = getchar();
    while (ch > '9'||ch < '0')
    {
        if (ch == '-') nega = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')sum = sum * 10 + ch - '0', ch = getchar();
    return sum * nega;
}
const int N = 4e5 + 9;
int T;
int n, need;
vector<int> G[N];
int son[N], siz[N], fason[N], ans[N], fa[N], max1son[N], max2son[N], maxson[N], ansson[N];
inline void dfs1(int u, int f)
{
    fa[u] = f;
    int faa = 0;
    for (int i = 0; i < G[u].size(); i++)
        if(G[u][i] != f)
        {
            int v = G[u][i];
            dfs1(v, u);
            siz[u] += siz[v];
            if(siz[v] > siz[faa]) faa = v;
            maxson[u] = max(maxson[u], maxson[v]);
        }
    if(n - siz[u] <= need)
    {
        if(siz[faa] - maxson[faa] <= need) ans[u] = 1;
    }
    if(siz[u] <= need) maxson[u] = siz[u];
}
inline void dfs2(int u, int f)
{
    if(n - siz[u] <= need) fason[u] = n - siz[u];
    for (int i = 0; i < G[u].size(); i++)
        if(G[u][i] != f)
        {
            int v = G[u][i];
            fason[v] = max(fason[v], fason[u]);
            if(n - siz[v] > need)
            {
                if(n - siz[v] - fason[v] <= need) ans[v] = 1;
            }
            dfs2(v, u);
        }
}
inline void dfs3(int u, int f)
{
    int ans1 = 0, ans2 = 0;
    for (int i = 0 ; i < G[u].size(); i++)
        if(G[u][i] != f)
        {
            int v = G[u][i];
            if(maxson[v] > ans1) ans2 = ans1, ans1 = maxson[v];
            else if(maxson[v] > ans2) ans2 = maxson[v];
        }
    for (int i = 0 ; i < G[u].size(); i++)
        if(G[u][i] != f)
        {
            int v = G[u][i];
            if(maxson[v] == ans1) ansson[v] = max(ansson[u], ans2);
            else ansson[v] = max(ansson[u], ans1);
            if(n - siz[v] > need)
            {
                if(n - siz[v] - ansson[v] <= need) ans[v] = 1;
            }
            dfs3(v, u);
        }
}
signed main()
{
//    freopen("reform.in","r",stdin);
//    freopen("reform.out","w",stdout);
    T = 1;
    for (int ttt = 1; ttt <= T; ttt++)
    {
        n = read();
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= n; i++) ans[i] = 0, siz[i] = 1, maxson[i] = 0, fason[i] = 0, ansson[i] = 0;
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        need = n / 2;
        dfs1(1, 0);
        dfs2(1, 0);
        dfs3(1, 0);
    //  for (int i = 1; i <= n; i++) cout << siz[i] << " " << maxson[i] << " " << fason[i] << " " << maxson[i] << endl;
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}