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
int s[V], K, n;
LL a[V];

void dfs(int u, int f) {
    s[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == f) continue;
        dfs(v, u);
        s[u] += s[v];
    }
    if (f != -1) a[K++] = (LL) s[u] * (n - s[u]);
}

int m, p[V], _, u, v;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            g[v].PB(u);
        }
        K = 0;
        dfs(1, -1);
        sort(a, a + n - 1);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) scanf("%d", &p[i]);
        int need = n - 1 - m;
        if (need > 0) for (int i = 0; i < need; ++i) p[m++] = 1;
        sort(p, p + m);
        int ans = 0;
        for (int i = 0; i < K - 1; ++i) ans = (ans + (LL) a[i] * p[i]) % P;
        int s = 1;
        for (int i = K - 1; i < m; ++i) s = (LL) s * p[i] % P;
        ans = (ans + (LL) a[K - 1] * s) % P;
        //for (int i = 0; i < K; ++i) printf("%d ", a[i]);puts("");
        //for (int i = 0; i < m; ++i) printf("%d ", p[i]);puts("");
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
4
1 2
2 3
3 4
2
2 2
4
3 4
1 3
3 2
2
3 2
7
6 1
2 3
4 6
7 3
5 1
3 6
4
7 5 13 3
*/