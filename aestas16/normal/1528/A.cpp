/*
    I will never forget it.
*/
 
// 392699
 
#include <bits/stdc++.h>
 
#define int long long
 
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
 
const int N = 1e5;
 
int n, l[N + 10], r[N + 10], f[N + 10][2];
 
namespace Edges {
    struct Edge {
        int to, nxt;
    } e[(N << 1) + 10];
    int etot = 1, hd[N + 10];
    void adde(int x, int y) { e[++etot] = {y, hd[x]}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;
 
void dfs(int u, int p) {
    bool flag = 0;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == p) continue;
        flag = 1, dfs(v, u);
        f[u][1] += max(abs(r[u] - l[v]) + f[v][0], abs(r[u] - r[v]) + f[v][1]), f[u][0] += max(abs(l[u] - l[v]) + f[v][0], abs(l[u] - r[v]) + f[v][1]);
    }
    // if (flag == 0) f[u][0] = l[u], f[u][1] = r[u];
}
 
struct OI {
    int RP, score;
} CSPS2021, NOIP2021;
 
signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        fr(n), memset(f, 0, sizeof(f)), etot = 1, memset(hd, 0, sizeof(hd));
        for (int i = 1; i <= n; i++) fr(l[i]), fr(r[i]);
        for (int i = 1, u, v; i < n; i++) fr(u), fr(v), adde(u, v), adde(v, u);
        dfs(1, 0), printf("%lld\n", max(f[1][0], f[1][1]));
    }
    return 0;
}