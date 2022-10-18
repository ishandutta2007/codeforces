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

const int N = 4e5, P = 1e9 + 7;

int vis[N + 10][2], a[N + 10][2], fa[N + 10];

int qpow(int a, int b) {
    int ret = 1;
    if (b < 0) return 0;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

int find(int u) {
    if (u == fa[u]) return u;
    return fa[u] = find(fa[u]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), ans = 0;
        for (int i = 1; i <= n; i++) fr(a[i][0]);
        for (int i = 1; i <= n; i++) fr(a[i][1]);
        for (int i = 1; i <= n; i++) vis[i][0] = vis[i][1] = 0, fa[i] = i;
        for (int i = 1; i <= n; i++) {
            if (vis[a[i][1]][0]) merge(i, vis[a[i][1]][0]);
            if (vis[a[i][0]][1]) merge(i, vis[a[i][0]][1]);
            vis[a[i][0]][0] = i, vis[a[i][1]][1] = i;
        }
        for (int i = 1; i <= n; i++)
            if (vis[find(i)][0] != n + 1) ans++, vis[find(i)][0] = n + 1;
        printf("%lld\n", qpow(2, ans));
    }
    return 0;
}