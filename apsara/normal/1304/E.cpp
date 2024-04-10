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
const int N = 20;
vector<int> g[V];
int d[V], f[V][N + 1], n;

void dfs(int u, int deep, int fa) {
    d[u] = deep;
    f[u][0] = fa;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, deep + 1, u);
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int t = d[u] - d[v];
    for (int i = 0; i < N; ++i) if (t & (1 << i)) u = f[u][i];
    if (u == v) return u;
    for (int i = N - 1; i >= 0; --i) {
        if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
    }
    return f[u][0];
}

int dis(int u, int v) {
    int t = lca(u, v);
    //printf("LCA %d %d %d\n", u ,v, t);
    return d[u] + d[v] - 2 * d[t];
}

void pre() {
    dfs(1, 0, -1);
    for (int i = 1; i < N; ++i) {
        for (int u = 1; u <= n; ++u) {
            if (f[u][i - 1] == -1) f[u][i] = -1;
            else f[u][i] = f[f[u][i - 1]][i - 1];
        }
    }
}

bool check(int x, int y, int a, int b, int K){
    //printf("CC %d %d %d %d %d\n", x, y, a, b, K);
    int dab = dis(a, b);
    int dxy = dis(x, y);
    int dax = dis(a, x);
    int day = dis(a, y);
    int dxb = dis(x, b);
    int dyb = dis(y, b);
    //printf("D %d %d %d %d %d %d\n", dab, dxy, dax, day, dxb, dyb);
    if (dab <= K && K % 2 == dab % 2) return true;
    if (dax + 1 + dyb <= K && K % 2 == (dax + 1 + dyb) % 2) return true;
    if (day + 1 + dxb <= K && K % 2 == (day + 1 + dxb) % 2) return true;
    //if (dax + dyb + dxy <= K && K % 2 == (dax + dyb + dxy) % 2) return true;
    //if (day + dxb + dxy <= K && K % 2 == (day + dxb + dxy) % 2) return true;
    return false;
}

int u, v, a, b, x, y, K, Q;
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            g[v].PB(u);
        }
        pre();
        scanf("%d", &Q);
        while (Q--) {
            scanf("%d%d%d%d%d", &x, &y, &a, &b, &K);
            bool ok = check(x, y, a, b, K);
            if (ok) puts("YES");
            else puts("NO");
        }
    }

    return 0;
}

/*
5
1 2
2 3
1 4
4 5
5
2 4 3 5 2
1 4 3 5 3
3 5 3 5 1
3 5 3 5 2

5
1 2
2 3
3 4
4 5
5
1 3 1 2 2
1 4 1 3 2
1 4 1 3 3
4 2 3 3 9
5 2 3 3 9

*/