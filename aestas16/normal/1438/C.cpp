/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e4;
const int nx[] = {0, 0, 0, -1, 1};
const int ny[] = {0, -1, 1, 0, 0};

namespace Edges {
    struct Edge {
        int to, nxt;
    } e[(N << 3) + 10];
    int etot, hd[N + 10];
    void adde(int x, int y) { e[++etot] = {y, hd[x]}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

int n, m, fa[N + 10], a[110][110];
bool vis[N + 10], vis1[N + 10], ans[N + 10];

int find(int u) {
    if (u == fa[u]) return u;
    return fa[u] = find(fa[u]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) fa[u] = v;
}

int id(int x, int y) {
    return (x - 1) * m + y;
}

void dfs(int u, int col) {
    vis1[u] = 1, ans[u] = col;
    // printf("dfs(%d, %d)\n", u, col);
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (vis1[v]) continue;
        dfs(v, col ^ 1);
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        n = fr(), m = fr(), etot = 1;
        for (int i = 1; i <= n * m; i++) fa[i] = i, vis[i] = vis1[i] = ans[i] = hd[i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) fr(a[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 1; k <= 4; k++) {
                    int x = i + nx[k], y = j + ny[k];
                    if (x < 1 || x > n || y < 1 || y > m) continue;
                    if (a[i][j] + 1 == a[x][y]) merge(id(i, j), id(x, y));
                }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                int p = find(id(i, j));
                // if (vis[p]) continue;
                // vis[p] = 1;
                for (int k = 1; k <= 4; k++) {
                    int x = i + nx[k], y = j + ny[k];
                    if (x < 1 || x > n || y < 1 || y > m) continue;
                    if (a[i][j] == a[x][y]) {
                        int q = find(id(x, y));
                        // printf("%d <-> %d\n", p, q);
                        adde(p, q), adde(q, p);
                    }
                }
            }
        for (int i = 1; i <= n * m; i++)
            if (fa[i] == i && vis1[i] == 0) dfs(i, 0);
        for (int i = 1; i <= n; i++, puts(""))
            for (int j = 1; j <= m; j++) {
                if (ans[find(id(i, j))]) a[i][j]++;
                printf("%d ", a[i][j]);
            }
    }
    return 0;
}