/*
     []
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 5e5;

int n, X[N + 10], Y[N + 10];
bool vis[N + 10], col[N + 10];
char ans[N + 10];

namespace Edges {
    struct Edge {
        int to, nxt;
    } e[(N << 1) + 10];
    int etot = 1, hd[N + 10];
    void adde(int x, int y) { e[++etot] = {y, hd[x]}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

void dfs(int u, int p) {
    vis[u] = 1, col[u] = col[p] ^ 1;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (vis[v]) continue;
        dfs(v, u);
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n);
    for (int i = 1, x, y; i <= n; i++) {
        fr(x), fr(y);
        if (X[x] == 0) X[x] = i;
        else adde(i, X[x]), adde(X[x], i), X[x] = 0;
        if (Y[y] == 0) Y[y] = i;
        else adde(i, Y[y]), adde(Y[y], i), Y[y] = 0;
    }
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0) dfs(i, 0);
    for (int i = 1; i <= n; i++) ans[i] = col[i] ? 'b' : 'r';
    puts(ans + 1);
    return 0;
}