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

const int V = 2010;

vector<int> g[V];

int n;
int lca[2][V][V], d[2][V], p[2][V];
vector<int> s[V];
int total;
void dfs(int id, int u) {
    //printf("dfs %d\n", u);
    s[u].clear();
    s[u].push_back(u);
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        //printf("%d\n", v);
        d[id][v] = d[id][u] + 1;
        dfs(id, v);
        for (int j = 0; j < s[u].size(); ++j) {
            int x = s[u][j];
            for (int k = 0; k < s[v].size(); ++k) {
                int y = s[v][k];
                lca[id][x][y] = lca[id][y][x] = d[id][u];
            }
        }
        for (int k = 0; k < s[v].size(); ++k) {
            int y = s[v][k];
            s[u].push_back(y);
        }
    }
}
void read(int id) {
    int m, u;
    scanf("%d", &m);
    total += m - 1;
    for (int i = 1; i <= m; ++i) g[i].clear();
    for (int i = 2; i <= m; ++i) {
        scanf("%d", &u);
        g[u].push_back(i);
    }
    d[id][1] = 0;
    dfs(id, 1);
    p[id][0] = 1;
    for (int i = 1; i <= n; ++i) scanf("%d", &p[id][i]);
}

int dp[V][V];
const int oo = 1000000000;
int main() {
    while (~scanf("%d", &n)) {
        total = 0;
        read(0);
        read(1);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = oo;
        dp[0][0] = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j) {
                if (dp[i][j] == oo) continue;
                //printf("DP %d %d %d\n", i, j, dp[i][j]);
                int mx = max(i, j);
                if (mx == n) continue;
                int pi = p[0][i];
                int pj = p[0][mx + 1];
                dp[mx + 1][j] = min(dp[mx + 1][j], dp[i][j] + d[0][pj] - lca[0][pi][pj]);
                pi = p[1][j];
                pj = p[1][mx + 1];
                dp[i][mx + 1] = min(dp[i][mx + 1], dp[i][j] + d[1][pj] - lca[1][pi][pj]);
            }
        int ans = oo;
        for (int i = 0; i < n; ++i) ans = min(ans, dp[i][n]), ans = min(ans, dp[n][i]);
        printf("%d\n", total - ans);
    }
    return 0;
}

/*
3
6
4 1 1 4 2
6 5 3
4
1 1 1
3 4 2

4
6
4 4 1 1 1
3 2 6 5
6
6 6 1 1 1
5 4 3 2

5
14
1 1 11 2 14 14 13 7 12 2 5 6 1
9 8 3 10 4
16
1 1 9 9 2 5 10 1 14 3 7 11 6 12 2
8 16 13 4 15

*/