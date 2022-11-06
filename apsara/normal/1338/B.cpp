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
const int V = 100100;
vector<int> g[V];
int dg[V], d[V];

void dfs(int u, int f) {
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == f) continue;
        d[v] = d[u] ^ 1;
        dfs(v, u);
    }
}
int n, u, v;
int main() {
    while (~scanf("%d", &n)) {
        memset(dg, 0, sizeof(dg));
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            dg[u]++;
            dg[v]++;
            g[u].PB(v);
            g[v].PB(u);
        }
        for (int i = 1; i <= n; ++i) {
            if (dg[i] != 1) {
                d[i] = 0;
                dfs(i, -1);
                break;
            }
        }
        int mid = 1, mxd = 0;
        for (int i = 1; i <= n; ++i) {
            if (dg[i] == 1) {
                mid = min(mid, d[i]);
                mxd = max(mxd, d[i]);
            }
        }
        int mi = 1;
        if (mid != mxd) mi = 3;
        int mx = n - 1;
        for (int i = 1; i <= n; ++i) {
            if (dg[i] == 1) continue;
            int ln = 0;
            for (int j = 0; j < g[i].size(); ++j) {
                v = g[i][j];
                if (dg[v] == 1) ln++;
            }
            if (ln > 0) mx -= ln - 1;
        }
        printf("%d %d\n", mi, mx);
    }
    return 0;
}

/*
6
1 3
2 3
3 4
4 5
5 6
6
1 3
2 3
3 4
4 5
4 6
7
1 2
2 7
3 4
4 7
5 6
6 7
*/