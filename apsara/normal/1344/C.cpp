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
const int V = 200100;
vector<int> g[2][V];

int n, m, Q[V], dg[V];
int vis[2][V];

void dfs(int u, int x) {
    //printf("D %d %d\n", u, x);
    for (int i = 0; i < g[x][u].size(); ++i) {
        int v = g[x][u][i];
        if (vis[x][v]) continue;
        vis[x][v] = 1;
        dfs(v, x);
    }
}

int ans[V], u, v;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) dg[i] = 0, g[0][i].clear(), g[1][i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            g[0][u].PB(v);
            g[1][v].PB(u);
            ++dg[v];
        }
        int top = 0, tail = 0;
        for (int i = 1; i <= n; ++i) {
            if (dg[i] == 0) {
                Q[++tail] = i;
            }
        }
        while (top != tail) {
            u = Q[++top];
            for (int i = 0; i < g[0][u].size(); ++i) {
                v = g[0][u][i];
                --dg[v];
                if (dg[v] == 0) {
                    Q[++tail] = v;
                }
            }
        }
        if (tail != n) {
            puts("-1");
        } else {
            memset(ans, 0, sizeof(ans));
            memset(vis, 0, sizeof(vis));
            int res = 0;
            for (int i = 1; i <= n; ++i) {
                if (!vis[0][i] && !vis[1][i]) {
                    ans[i] = 1;
                    ++res;
                }
                vis[0][i] = vis[1][i] = 1;
                dfs(i, 0);
                dfs(i, 1);
            }
            //printf("%d\n", ans[26]);
            printf("%d\n", res);
            for (int i = 1; i <= n; ++i) {
                if (ans[i] == 1) putchar('A');
                else putchar('E');
            } puts("");
        }
    }
    return 0;
}

/*
2 1
1 2
4 3
1 2
2 3
3 1
3 2
1 3
2 3
*/