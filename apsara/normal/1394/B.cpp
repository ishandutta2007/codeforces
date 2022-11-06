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
const int V = 200200;
vector<PII> g[V], diff;
int n, m, K;
int has[V][100];
int conf[100], vis[100];
int D[120][120];
int ans;

void dfs(int id) {
    if (id >= K) {
        bool ok = true;
        for (int i = 0; i < diff.size(); ++i) {
            PII p = diff[i];
            if (vis[p.fi] && vis[p.se]) {ok = false; break;}
        }
        if (ok) ++ans;
        return;
    }
    for (int i = 0; i <= id; ++i) {
        if (conf[id * K + i]) continue;
        vis[id * K + i] = 1;
        dfs(id + 1);
        vis[id * K + i] = 0;
    }
}

int u, v, w;

int main() {
    while (~scanf("%d%d%d", &n, &m, &K)) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            g[u].PB(MP(w, v));
        }
        for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
        memset(has, 0, sizeof(has));
        for (int i = 1; i <= n; ++i) {
            int dg = g[i].size();
            for (int j = 0; j < dg; ++j) {
                int k = g[i][j].se;
                has[k][(dg - 1) * K + j] += 1;
            }
        }
        memset(conf, 0, sizeof(conf));
        diff.clear();
        memset(D, 0, sizeof(D));
        for (int i = 1; i <= n; ++i) {
            vector<int> one;
            for (int j = 0; j < K * K; ++j) {
                if (has[i][j] > 1) conf[j] = 1;
                if (has[i][j] == 1) one.PB(j);
            }
            for (int j = 0; j < one.size(); ++j) {
                for (int k = 0; k < j; ++k) {
                    D[one[j]][one[k]] = 1;
                }
            }
        }
        for (int j = 0; j < K * K; ++j) {
            for (int k = 0; k < j; ++k) {
                if (D[j][k])
                    diff.PB(MP(j, k));
            }
        }
        //for (int j = 0; j < K * K; ++j) if (conf[j]) printf("Conf %d\n", j);
        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}

/*
4 6 3
4 2 1
1 2 2
2 4 3
4 1 4
4 3 5
3 1 6

5 5 1
1 4 1
5 1 2
2 5 3
4 3 4
3 2 5

6 13 4
3 5 1
2 5 2
6 3 3
1 4 4
2 6 5
5 3 6
4 1 7
4 3 8
5 2 9
4 2 10
2 1 11
6 1 12
4 6 13
*/