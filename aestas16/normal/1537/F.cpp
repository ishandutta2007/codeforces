/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 4e5;

int n, m, tot, val[N + 10], acc[N + 10], sum[N + 10];
bool vis[N + 10];

namespace Edges {
    struct Edge {
        int to, nxt;
    } e[(N << 1) + 10];
    int etot = 1, hd[N + 10];
    void adde(int x, int y) { e[++etot] = {y, hd[x]}, hd[x] = etot; }
} // namespace Edge
using namespace Edges;

void dfs(int u, int p) {
    vis[u] = 1, acc[u] = p, sum[p] += val[u];
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (vis[v]) continue;
        dfs(v, p);
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int ans = 1;
        fr(n), fr(m), etot = 1, tot = 0;
        for (int i = 1; i <= (n << 1); i++) hd[i] = sum[i] = vis[i] = 0, fr(val[i]);
        for (int i = 1, x, y; i <= m; i++) fr(x), fr(y), adde(x, y + n), adde(y + n, x), adde(y, x + n), adde(x + n, y);
        for (int i = 1; i <= (n << 1); i++)
            if (vis[i] == 0) dfs(i, ++tot);
        for (int i = 1; i <= n; i++)
            if (acc[i] == acc[i + n]) ans &= ((sum[acc[i]] & 1) == 0);
            else ans &= (sum[acc[i]] == sum[acc[i + n]]);
        puts(ans ? "YES" : "NO");
    }
    return 0;
}