#include <bits/stdc++.h>

using namespace std;

#ifdef ONLINE_JUDGE
    #define getchar() (_S == _T && (_T = (_S = _B) + fread(_B, 1, 1 << 15, stdin), _S == _T) ? EOF : *_S++)
#endif
char _B[1 << 15], *_S = _B, *_T = _B;

template <class T> inline void fr(register T &a, register bool f = 0, register char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    f ? a = - a : 0;
}
template <class T, class ...Y> inline void fr(register T &t, register Y &...a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 3e5, M = 6e5;

int n, m, ans, deg[N + 10], val[N + 10], vis[N + 10];
namespace Edges {
    struct Edge { int to, nxt, val, ans; } e[(M << 1) + 10];
    int etot = 1, hd[N + 10];
    vector<int> E[N + 10][3];
    inline void adde(register int x, register int y, register int z) { e[++etot] = {y, hd[x], z, -1}, hd[x] = etot, E[x][z].push_back(etot); }
} // namespace Edges
using namespace Edges;

void dfs(register int u, register int lstw) {
    register bool flag = 0;
    vis[u] = 1;
    for (register auto i = E[u][lstw].rbegin(); i != E[u][lstw].rend(); i++, E[u][lstw].pop_back()) {
        if (e[*i].ans == -1) {
            e[*i].ans = 0, e[*i ^ 1].ans = 1, dfs(e[*i].to, e[*i].val), flag = 1;
            break;
        }
    }
    if (flag == 0) {
        register int ww = ((lstw - 1) ^ 1) + 1;
        for (register auto i = E[u][ww].rbegin(); i != E[u][ww].rend(); i++, E[u][ww].pop_back()) {
            if (e[*i].ans == -1) {
                e[*i].ans = 0, e[*i ^ 1].ans = 1, dfs(e[*i].to, e[*i].val), flag = 1;
                break;
            }
        }
    }
    if (flag == 0) return ;
    for (register int &i = hd[u]; i; i = e[i].nxt) {
        register int v = e[i].to, w = e[i].val;
        if (e[i].ans == -1) e[i].ans = 0, e[i ^ 1].ans = 1, dfs(v, w);
    }
}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n, m);
    for (register int i = 1, x, y, z; i <= m; i++) fr(x, y, z), adde(x, y, z), adde(y, x, z), deg[x]++, deg[y]++;
    for (register int i = 1; i <= n; i++)
        if (deg[i] & 1) adde(n + 1, i, 1), adde(i, n + 1, 1);
    for (register int i = 1; i <= n; i++)
        if (vis[i] == 0) dfs(i, 1);
    for (register int i = 1; i <= m; i++)
        if (e[i << 1].ans) val[e[i << 1].to] += e[i << 1].val, val[e[i << 1 | 1].to] -= e[i << 1 | 1].val;
        else val[e[i << 1].to] -= e[i << 1].val, val[e[i << 1 | 1].to] += e[i << 1 | 1].val;
    for (register int i = 1; i <= n; i++) ans += (abs(val[i]) == 1);
    printf("%d\n", ans);
    for (register int i = 1; i <= m; i++) printf("%d", e[i << 1].ans + 1);
    return puts(""), 0;
}