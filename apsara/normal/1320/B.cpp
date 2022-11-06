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
vector<int> g[V], rg[V];
int d[V], a[V], n, m, u, v, Q, q[V];
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) g[i].clear(), rg[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            rg[v].PB(u);
        }
        memset(d, -1, sizeof(d));
        scanf("%d", &Q);
        for (int i = 0; i < Q; ++i) scanf("%d", &a[i]);
        int t = a[Q - 1];
        memset(d, -1, sizeof(d));
        d[t] = 0;
        int top = 0, tail = 0;
        q[++tail] = t;
        while (top != tail) {
            u = q[++top];
            for (int i = 0; i < rg[u].size(); ++i) {
                v = rg[u][i];
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q[++tail] = v;
                }
            }
        }
        int mi = 0, mx = 0;
        for (int i = 0; i < Q - 1; ++i) {
            u = a[i];
            int cnt = 0;
            bool ok = (d[a[i]] == d[a[i + 1]] + 1);
            for (int j = 0; j < g[u].size(); ++j) {
                v = g[u][j];
                if (d[u] == d[v] + 1) cnt++;
            }
            if (!ok) ++mi;
            if (!ok || cnt > 1) mx++;
        }
        printf("%d %d\n", mi, mx);
    }
    return 0;
}

/*
6 9
1 5
5 4
1 2
2 3
3 4
4 1
2 6
6 4
4 2
4
1 2 3 4
7 7
1 2
2 3
3 4
4 5
5 6
6 7
7 1
7
1 2 3 4 5 6 7
8 13
8 7
8 6
7 5
7 4
6 5
6 4
5 3
5 2
4 3
4 2
3 1
2 1
1 8
5
8 7 5 2 1
*/