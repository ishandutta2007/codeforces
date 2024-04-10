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
const int ooo = 1e9;
const LL oo = (LL) ooo * ooo;
const int V = 200100;

int mx[V], mi[V], _, n, D;
vector<int> g[V], lv[V];
LL dp[V];
int d[V], f[V], a[V];
bool cmp(int x, int y) {
    return a[x] < a[y];
}

bool cmpf(int x, int y) {
    return a[f[x]] < a[f[y]];
}

void dfs(int u, int fa) {
    D = max(D, d[u]);
    f[u] = fa;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int x;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        a[1] = 0;
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &x);
            g[x].PB(i);
            g[i].PB(x);
        }
        for (int i = 2; i <= n; ++i) scanf("%d", &a[i]);
        d[1] = 0;
        D = 0;
        dfs(1, -1);
        for (int i = 0; i <= D; ++i) mi[i] = 1e9 + 1, mx[i] = -1;
        for (int i = 1; i <= n; ++i) mx[d[i]] = max(mx[d[i]], a[i]), mi[d[i]] = min(mi[d[i]], a[i]);
        for (int i = 0; i <= D; ++i) lv[i].clear();
        for (int i = 1; i <= n; ++i) lv[d[i]].PB(i);
        dp[1] = 0;
        LL ans = 0;
        for (int i = 1; i <= D; ++i) {
            sort(lv[i].begin(), lv[i].end(), cmpf);
            for (int j = 0; j < lv[i].size(); ++j) {
                int u = lv[i][j];
                dp[u] = dp[f[u]] + max(a[f[u]] - mi[i - 1], mx[i - 1] - a[f[u]]);
                //printf("Dp %d %I64d\n", u, dp[u]);
            }
            int p = 0;
            LL tmx = -oo;
            for (int j = 0; j < lv[i].size(); ++j) {
                int u = lv[i][j];
                while (p < lv[i - 1].size() && a[lv[i - 1][p]] <= a[f[u]]) {
                    int v = lv[i - 1][p];
                    //printf("ADD %d\n", v);
                    tmx = max(tmx, dp[v] - a[v]);
                    ++p;
                }
                dp[u] = max(dp[u], tmx + a[f[u]]);
                //printf("Dp %d %d %I64d %I64d\n", u, p, tmx, dp[u]);
            }
            p = lv[i - 1].size() - 1, tmx = -oo;
            for (int j = lv[i].size() - 1; j >= 0; --j) {
                int u = lv[i][j];
                while (p >= 0 && a[lv[i - 1][p]] >= a[f[u]]) {
                    int v = lv[i - 1][p];
                    //printf("ADD %d\n", v);
                    tmx = max(tmx, dp[v] + a[v]);
                    --p;
                }
                dp[u] = max(dp[u], tmx - a[f[u]]);
                //printf("Dp %d %d %I64d %I64d\n", u, p, tmx, dp[u]);
            }
            if (i == D) {
                for (int j = 0; j < lv[i].size(); ++j) {
                    int u = lv[i][j];
                    ans = max(ans, dp[u] + max(a[u] - mi[i], mx[i] - a[u]));
                }
            }
            sort(lv[i].begin(), lv[i].end(), cmp);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
4
14
1 1 1 2 3 4 4 5 5 6 7 8 8
2 3 7 7 6 9 5 9 7 3 6 6 5
6
1 2 2 3 4
32 78 69 5 41
15
1 15 1 10 4 9 11 2 4 1 8 6 10 11
62 13 12 43 39 65 42 86 25 38 19 19 43 62
15
11 2 7 6 9 8 10 1 1 1 5 3 15 2
50 19 30 35 9 45 13 24 8 44 16 26 10 40
*/