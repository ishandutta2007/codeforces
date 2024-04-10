/*
     []
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

#define getchar() (_S == _T && (_T = (_S = _B) + fread(_B, 1, 1 << 24, stdin), _S == _T) ? EOF : *_S++)

char _B[1 << 24], *_S = _B, *_T = _B;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 25e2;

int n, a[N + 10][N + 10], dis[N + 10], qwq[N + 10];
bool vis[N + 10];

namespace Edges {
    struct Edge {
        int to, nxt, val;
    } e[(N << 1) + 10];
    int etot = 1, hd[N + 10];
    void adde(int x, int y, int z) { e[++etot] = {y, hd[x], z}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

bool dfs(int u, int p, int cur, int val) {
    if (a[cur][u] != val) return 1;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == p) continue;
        if (dfs(v, u, cur, max(e[i].val, val))) return 1;
    }
    return 0;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) fr(a[i][j]);
    for (int i = 1; i <= n; i++)
        if (a[i][i]) return puts("NOT MAGIC"), 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (a[i][j] != a[j][i]) return puts("NOT MAGIC"), 0;
    dis[0] = 0x7f7f7f7f, vis[1] = 1;
    for (int i = 2; i <= n; i++) dis[i] = a[1][i], qwq[i] = 1;
    for (int i = 2; i <= n; i++) {
        int p = 0;
        for (int j = 1; j <= n; j++)
            if (vis[j] == 0 && (dis[j] < dis[p] || p == 0)) p = j;
        vis[p] = 1, adde(qwq[p], p, dis[p]), adde(p, qwq[p], dis[p]);
        for (int j = 1; j <= n; j++)
            if (vis[j] == 0 && a[p][j] < dis[p]) dis[j] = a[p][j], qwq[j] = p;
    }
    for (int i = 1; i <= n; i++)
        if (dfs(i, i, i, 0)) return puts("NOT MAGIC"), 0;
    puts("MAGIC");
    return 0;
}