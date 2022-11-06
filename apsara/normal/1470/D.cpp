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
const int V = 300100;
int f[V];
int fd(int x) {
    if (x != f[x]) f[x] = fd(f[x]);
    return f[x];
}

void U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px == py) return;
    f[px] = py;
}

vector<int> g[V];
int vis[V], ans[V], st[V], m;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    if (st[u] == 1) {
        ans[m++] = u;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            st[v] = 0;
            U(u, v);
        }
    }
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        dfs(v);
    }
}

int _, n, u, v;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) f[i] = i, vis[i] = 0, g[i].clear(), st[i] = 1;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            g[v].PB(u);
        }
        m = 0;
        for (int i = 1; i <= n; ++i) if (vis[i] == 0) dfs(i);
        /*
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            ans[m++] = i;
            for (int j = 0; j < g[i].size(); ++j) {
                int k = g[i][j];
                vis[k] = 1;
                U(i, k);
            }
        }*/
        bool ok = true;
        for (int i = 2; i <= n; ++i) if(fd(i) != fd(1)) ok = false;
        if (!ok) puts("NO");
        else {
            puts("YES");
            printf("%d\n", m);
            for (int i = 0; i < m; ++i) printf("%d ", ans[i]); puts("");
        }
    }
    return 0;
}

/*
2
3 2
3 2
2 1
4 2
1 4
2 3

1
17 27
1 8
2 9
3 10
4 11
5 12
6 13
7 14
8 9
8 14
8 15
9 10
9 15
10 11
10 15
10 17
11 12
11 17
12 13
12 16
12 17
13 14
13 16
14 16
14 15
15 16
15 17
16 17
*/