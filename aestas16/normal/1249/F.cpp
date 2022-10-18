#include <bits/stdc++.h>

using namespace std;

#ifdef ONLINE_JUDGE
    #define getchar() (_S == _T && (_T = (_S = _B) + fread(_B, 1, 1 << 20, stdin), _S == _T) ? EOF : *_S++)
#endif
char _B[1 << 20], *_S = _B, *_T = _B;

template <class T> inline void fr(register T &a, register bool f = 0, register char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> inline void fr(register T &t, register Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e6;

int n, k, a[N + 10], ht[N + 10], ch[N + 10], etot, hd[N + 10];
long long mem[N + 10], *atot = mem, *f[N + 10];
struct Edge { int to, nxt; } e[(N << 1) + 10];

inline void adde(register int u, register int v) { e[++etot] = {v, hd[u]}, hd[u] = etot; }

void dfs(register int u, register int p) {
    ht[u] = 1;
    for (register int i = hd[u]; i; i = e[i].nxt) {
        register int v = e[i].to;
        if (v == p) continue;
        dfs(v, u), ht[u] = max(ht[u], ht[v] + 1);
        if (ht[v] > ht[ch[u]]) ch[u] = v;
    }
}
#define F(u, d) (((d) < ht[u]) ? f[u][d] : 0)
void dfs1(register int u, register int p) {
    if (f[u] == 0) f[u] = atot, atot += ht[u];
    if (ch[u]) f[ch[u]] = f[u] + 1, dfs1(ch[u], u);
    f[u][0] = max(a[u] + F(u, k + 1), F(u, 1));
    for (register int i = hd[u]; i; i = e[i].nxt) {
        register int v = e[i].to;
        if (v == p || v == ch[u]) continue;
        dfs1(v, u), f[u][0] += F(v, k);
        for (register int d = 1; d <= ht[v]; d++)
            if (d * 2 <= k) f[u][d] = max(f[u][d] + F(v, k - d), F(u, k - d + 1) + f[v][d - 1]);
            else f[u][d] += f[v][d - 1];
        for (register int d = min(ht[v], ht[u] - 2); ~d; d--) f[u][d] = max(f[u][d], f[u][d + 1]);
    }
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, k);
    for (register int i = 1; i <= n; i++) fr(a[i]);
    for (register int i = 1, x, y; i < n; i++) fr(x, y), adde(x, y), adde(y, x);
    dfs(1, 0), dfs1(1, 0), printf("%lld\n", f[1][0]);
    return 0;
}