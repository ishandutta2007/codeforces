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
const int V = 610;
const int En = V * V;
LL d[V][V], E[V][V];
int a[En], b[En], l[V][V], ok[V][V];
int n, m, Q, u, v, w;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = E[i][i] = oo;
        for (int i = 1; i <= n; ++i) d[i][i] = E[i][i] = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            d[u][v] = d[v][u] = w;
            E[u][v] = E[v][u] = w;
            a[i] = u;
            b[i] = v;
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        memset(ok, 0, sizeof(ok));
        memset(l, -1, sizeof(l));
        scanf("%d", &Q);
        for (int i = 0; i < Q; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            l[u][v] = l[v][u] = w;
        }
        for (u = 1; u <= n; ++u) {
            for (int y = 1; y <= n; ++y) {
                LL mx = -1;
                for (v = 1; v <= n; ++v) mx = max(mx, l[u][v] - d[y][v]);
                //printf("Mx %d %d %lld %lld\n", u, y, mx, d[u][1] + E[1][4]);
                for (int x = 1; x <= n; ++x) if (d[u][x] + E[x][y] <= mx) ok[x][y] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i)
            if (ok[a[i]][b[i]]) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}

/*
4 6
1 2 1
2 3 1
3 4 1
1 3 3
2 4 3
1 4 5
1
1 4 4

4 2
1 2 10
3 4 10
6
1 2 11
1 3 11
1 4 11
2 3 11
2 4 11
3 4 9

3 2
1 2 1
2 3 2
1
1 2 5
*/