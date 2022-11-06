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

using namespace std;
typedef long long LL;

const int V = 3010;
vector<int> g[V];
const int ooo = 1000000000;
const LL oo = (LL) ooo * ooo;
LL dp[V][V];
int d[V][V];
int s[V][V];

void dfs(int root, int u, int f) {
    s[root][u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == f) continue;
        d[root][v] = d[root][u] + 1;
        dfs(root, v, u);
        s[root][u] += s[root][v];
    }
}
struct Event{
    int u, v;
};
vector<Event> e[V];

int n;
int u, v;
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            d[i][i] = 0;
            dfs(i, i, -1);
        }
        for (int i = 0; i <= n; ++i) e[i].clear();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                Event ne;
                ne.u = i;
                ne.v = j;
                e[d[i][j]].push_back(ne);
            }
        LL ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = -oo;
        for (int i = 0; i <= n; ++i) {
            for (int k = 0; k < e[i].size(); ++k) {
                u = e[i][k].u;
                v = e[i][k].v;
                if (u == v) dp[u][v] = 0;
                else if (d[u][v] == 1) {
                    dp[u][v] = s[u][v] * s[v][u];
                }
                if (u != v) {
                    for (int j = 0; j < g[u].size(); ++j) {
                        int w = g[u][j];
                        if (d[w][v] != d[u][v] + 1) continue;
                        dp[w][v] = max(dp[w][v], dp[u][v] + s[u][w] * s[u][v]);
                    }
                    for (int j = 0; j < g[v].size(); ++j) {
                        int w = g[v][j];
                        if (d[u][w] != d[u][v] + 1) continue;
                        dp[u][w] = max(dp[u][w], dp[u][v] + s[v][u] * s[v][w]);
                    }
                }
                ans = max(ans, dp[u][v]);
                //printf("DP %d %d %d %I64d\n", u, v, d[u][v], dp[u][v]);
            }
        }
        printf("%I64d\n", ans);

    }
    return 0;
}

/*
3
1 2
2 3

5
1 2
1 3
1 4
3 5

*/