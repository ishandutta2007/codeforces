#include <cstdio>
#include <cstring>

const int N = 1e5, INF = 0x3f3f3f3f;

int n, m, q, d, ETOT, a[N + 10], dep[2][N + 10];

namespace Edges {
    struct Edge {
        int to, nxt, id;
    } e[(N << 1) + 10];
    int etot, Etot, hd[N + 10];
    void adde(int x, int y, int z) { e[++etot] = {y, hd[x], z}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

void dfs(int u, int p, int op) {
    dep[op][u] = dep[op][p] + 1;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == p) continue;
        dfs(v, u, op);
    }
}

void work() {
    int l = 0, ans = 0; dfs(a[1], 0, 0);
    for (int i = 1; i <= m; i++) if (dep[0][l] < dep[0][a[i]]) l = a[i];
    dfs(l, 0, 0), l = 0;
    for (int i = 1; i <= m; i++) if (dep[0][l] < dep[0][a[i]]) l = a[i];
    dfs(l, 0, 1);
    for (int i = 1; i <= n; i++) if (dep[0][i] <= d && dep[1][i] <= d) ans++;
    printf("%d\n", ans);
}

struct NOIP2020 {
    int RP, score;
} NOIP2020;

int main() {
    NOIP2020.RP++, NOIP2020.score++;
    scanf("%d%d%d", &n, &m, &d), ETOT = n - 1, dep[0][0] = dep[1][0] = -1;
    for (int i = 1; i <= m; i++) scanf("%d", a + i);
    for (int i = 1, x, y; i < n; i++) scanf("%d%d", &x, &y), adde(x, y, i), adde(y, x, i);
    work();
    return 0;
}