#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int n, tot, Head[N], Dfn[N], Size[N], Ad[N][26];

struct Edge
{
    int next, node;
}h[N << 1];

inline void addedge(int u, int v)
{
    h[++ tot].next = Head[u], Head[u] = tot;
    h[tot].node = v;
    h[++ tot].next = Head[v], Head[v] = tot;
    h[tot].node = u;
}

inline void dfs(int z, int fa)
{
    Size[z] = 1;
    for (int i = Head[z]; i; i = h[i].next)
    {
        int d = h[i].node;
        if (d == fa) continue ;
        Dfn[d] = Dfn[z] + 1;
        Ad[d][0] = z;
        for (int j = 1, x = z; x; x = Ad[x][j - 1], j ++)
            Ad[d][j] = Ad[x][j - 1];
        dfs(d, z);
        Size[z] += Size[d];
    }
}

inline int LCA(int u, int v)
{
    if (Dfn[u] < Dfn[v]) swap(u, v);
    int d = Dfn[u] - Dfn[v];
    for (int i = 25; i >= 0; i --)
        if (d & (1 << i))
        {
            u = Ad[u][i];
            d -= (1 << i);
        }
    if (u == v) return u;
    for (int i = 25; Ad[u][0] != Ad[v][0] && i >= 0; i --)
    {
        if (Ad[u][i] != Ad[v][i])
            u = Ad[u][i], v = Ad[v][i];
    }
    return Ad[u][0];
}

inline int Find(int x, int d)
{
    d = Dfn[x] - d;
    for (int i = 25; i >= 0; i --)
        if (d & (1 << i))
        {
            x = Ad[x][i];
            d -= (1 << i);
        }
    return x;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    dfs(1, 0);
    int T;
    scanf("%d", &T);
    while (T --)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if ((Dfn[u] + Dfn[v]) % 2 == 1) puts("0");
        else if (u == v) printf("%d\n", n);
        else
        {
            int lca = LCA(u, v);
            if (Dfn[u] == Dfn[v])
            {
                int _u = Find(u, Dfn[lca] + 1);
                int _v = Find(v, Dfn[lca] + 1);
                int res = n - Size[_u] - Size[_v];
                printf("%d\n", res);
            }
            else
            {
                if (Dfn[u] < Dfn[v]) swap(u, v);
                int mid = (Dfn[u] - Dfn[v]) / 2 + Dfn[lca];
                int _u = Find(u, mid);
                int _v = Find(u, mid + 1);
                int res = Size[_u] - Size[_v];
                printf("%d\n", res);
            }
        }
    }
    
    return 0;
}