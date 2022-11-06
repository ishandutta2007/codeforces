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

const int V = 200100;
struct Edge {int v, w, ne;}e[2 * V];
int p[V], K;
void add(int u, int v, int w) {
    e[K].v = v; e[K].w = w;
    e[K].ne = p[u]; p[u] = K++;
}

int s[V], n;
LL ans1, ans2;

void dfs(int u, int f) {
    s[u] = 1;
    for (int i = p[u]; i != -1; i = e[i].ne) {
        int v = e[i].v;
        if (v == f) continue;
        dfs(v, u);
        if (s[v] % 2 == 1) ans1 += e[i].w;
        ans2 += (LL) e[i].w * min(s[v], n - s[v]);
        s[u] += s[v];
    }
}

int _, w, u, v;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        n *= 2;
        for (int i = 1; i <= n; ++i) p[i] = -1; K = 0;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        ans1 = ans2 = 0;
        dfs(1, -1);
        printf("%I64d %I64d\n", ans1, ans2);
    }
    return 0;
}

/*
2
3
1 2 3
3 2 4
2 4 3
4 5 6
5 6 5
2
1 2 1
1 3 2
1 4 3

*/