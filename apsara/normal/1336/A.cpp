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
vector<int> g[V];
int s[V], d[V], a[V];

void dfs(int u, int f) {
    s[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == f) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
        s[u] += s[v];
    }
}
int n, K, u, v;
int main() {
    while (~scanf("%d%d", &n, &K)) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            g[v].PB(u);
        }
        d[1] = 0;
        dfs(1, -1);
        for (int i = 1; i <= n; ++i) a[i] = d[i] - s[i] + 1;
        //for (int i = 1; i <= n; ++i) printf("%d ", a[i]);puts("");
        sort(a + 1, a + 1 + n);
        LL ans = 0;
        for (int i = 0; i < K; ++i) ans += a[n - i];
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
7 4
1 2
1 3
1 4
3 5
3 6
4 7
4 1
1 2
1 3
2 4
8 5
7 5
1 7
6 1
3 7
8 3
2 1
4 5
*/