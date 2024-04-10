#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 1010;
vector<int> g[V];
int n, deg[V], vis[V], f[V];

void root(int u, int fa) {
    f[u] = fa;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        root(v, u);
    }
}

void dfs(int u, int fa) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) deg[g[u][i]]--;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
    }
}

void col(int u, int v) {
    if (u == v) return;
    root(u, -1);
    while (f[v] != u) v = f[v];
    dfs(v, u);
}

int u, v;
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            g[v].PB(u);
            deg[u]++; deg[v]++;
        }
        memset(vis, 0, sizeof(vis));
        while (1) {
            u = -1;
            for (int i = 1; i <= n; ++i) {
                if (vis[i]) continue;
                if (u == -1 || deg[u] < deg[i]) u = i;
            }
            int x = -1, y = -1;
            for (int i = 0; i < g[u].size(); ++i) {
                v = g[u][i];
                if (vis[v]) continue;
                if (x == -1) x = v;
                else if (y == -1) y = v;
            }
            if (x == -1) {
                printf("! %d\n", u);
                fflush(stdout);
                break;
            }
            if (y == -1) y = u;
            printf("? %d %d\n", x, y);
            fflush(stdout);
            int z;
            scanf("%d", &z);
            col(z, x);
            col(z, y);
        }
    }
    return 0;
}

/*
6
1 4
4 2
5 3
6 3
2 3
*/