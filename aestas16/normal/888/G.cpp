// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef Aestas16
    #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
    #define debug(...) 0
#endif

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5, S = 30, INF = 0x7f7f7f7f;

int n, rt, ptot = 1, qwq, ans, ch[N * S + 10][2], sz[N * S + 10], dep[N * S + 10];

void dfs1(int u, int val) {
    if (dep[u] == 0) {
        int v = rt, t = dep[rt] - 1, k = (1 << dep[rt]);
        for (int i = t; ~i; i--) {
            int f = (val >> i) & 1;
            if (ch[v][f]) v = ch[v][f];
            else v = ch[v][f ^ 1], k |= (1 << i);
        }
        qwq = min(qwq, k);
        return;
    }
    if (ch[u][0]) dfs1(ch[u][0], val);
    if (ch[u][1]) dfs1(ch[u][1], val | (1 << dep[ch[u][1]]));
}
void dfs(int u) {
    if (ch[u][0]) dfs(ch[u][0]);
    if (ch[u][1]) dfs(ch[u][1]);
    if (ch[u][0] && ch[u][1]) {
        int f = (sz[ch[u][0]] < sz[ch[u][1]]);
        rt = ch[u][f], qwq = INF, dfs1(ch[u][f ^ 1], 0), ans += qwq;
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n);
    for (int i = 1, x; i <= n; i++) {
        fr(x);
        int u = 1;
        for (int j = S; ~j; j--) {
            int f = (x >> j) & 1;
            if (ch[u][f] == 0) ch[u][f] = ++ptot;
            u = ch[u][f], dep[u] = j, sz[u]++;
        }
    }
    dfs(1), printf("%lld\n", ans);
    return 0;
}