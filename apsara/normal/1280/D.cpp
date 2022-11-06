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
const int ooo = 1000000000;
const LL oo = (LL) ooo * ooo;
struct Edge {int v, ne;}e[2 * V];
int p[V], K;

void add(int u, int v) {
    e[K].v = v;
    e[K].ne = p[u];
    p[u] = K++;
}

struct Node{
    int c;
    LL v;
    //Node(int _c, LL _v):c(_c), v(_v){}
}dp[V][V], t[V];

Node N(int c, LL v) {
    Node res;
    res.c = c;
    res.v = v;
    return res;
}

bool good(Node x, Node y) {
    if (x.c != y.c) return x.c > y.c;
    return x.v > y.v;
}

Node add(Node x, Node y) {
    return N(x.c + y.c, x.v + y.v);
}

int s[V], a[V], n, m;


void dfs(int u, int f) {
    s[u] = 1;
    dp[u][0] = N(0, a[u]);
    for (int i = p[u]; i != -1; i = e[i].ne) {
        int v = e[i].v;
        if (v == f) continue;
        dfs(v, u);
        for (int j = 0; j < s[u] + s[v]; ++j)
            t[j] = N(0, -oo);
        for (int j = 0; j < s[v]; ++j) {
            if (dp[v][j].v == -oo) continue;
            for (int k = 0; k < s[u]; ++k) {
                if (dp[u][k].v == -oo) continue;
                Node div = N(dp[v][j].c + dp[u][k].c + (dp[v][j].v > 0), dp[u][k].v);
                if (good(div, t[j + k + 1])) t[j + k + 1] = div;
                Node meg = N(dp[v][j].c + dp[u][k].c, dp[u][k].v + dp[v][j].v);
                if (good(meg, t[j + k])) t[j + k] = meg;
                //printf("trans %d %d %d %d %I64d %d %I64d %d %I64d\n", u, v, j, k, dp[u][k].v, div.c, div.v, meg.c, meg.v);
            }
        }
        for (int j = 0; j < s[u] + s[v]; ++j) dp[u][j] = t[j];
        s[u] += s[v];
    }
    //if (s[u] == 1) dp[u][0] = N(0, a[u]);
    //for (int i = 0; i < s[u]; ++i) printf("DP %d %d %d %I64d\n", u, i, dp[u][i].c, dp[u][i].v);
}

int _, u, v;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &u);
            a[i] = u - a[i];
        }
        for (int i = 1; i <= n; ++i) p[i] = -1; K = 0;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        dfs(1, -1);
        int ans = 0;
        //ans = max(ans, dp[1][m].c);
        ans = max(ans, dp[1][m - 1].c + (dp[1][m - 1].v > 0));
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
2 1
2 1
1 2
1 2
4 3
10 160 70 50
70 111 111 0
1 2
2 3
3 4
2 1
143 420
214 349
2 1

*/