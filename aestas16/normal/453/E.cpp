#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class N> void fr(N &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class N, class... Y> void fr(N &up, Y &... a) { fr(up), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e5, M = 4e2, S = N / M;

int n, up, tim[N + 10], bl[S + 10], br[S + 10], bid[N + 10], g[N + 10], s[N + 10], m[N + 10], k[N + 10], f[S + 10][N + 10];
bool vis[S + 10];

void Init() {
    up = n / M;
    for (int i = 1; i <= up; i++) bl[i] = br[i - 1] + 1, br[i] = M * i;
    if (br[up] < n) up++, bl[up] = br[up - 1] + 1, br[up] = n;
    for (int i = 1; i <= up; i++) {
        for (int j = bl[i]; j <= br[i]; j++) if (k[j]) g[1] += k[j], g[m[j] / k[j] + 1] -= k[j];
        for (int j = 1; j <= N; j++) g[j] += g[j - 1];
        for (int j = bl[i]; j <= br[i]; j++) if (k[j]) g[m[j] / k[j] + 1] += m[j] % k[j];
        for (int j = 1; j <= N; j++) g[j] += g[j - 1];
        for (int j = 1; j <= N; j++) f[i][j] = g[j], g[j] = 0;
        for (int j = bl[i]; j <= br[i]; j++) bid[j] = i;
        vis[i] = 1;
    }
}

int modify(int b, int l, int r, int now) {
    int ret = 0;
    if (vis[b]) {
        for (int i = l; i <= r; i++) ret += min(m[i], s[i] + k[i] * (now - tim[i])), s[i] = 0, tim[i] = now;
        return ret;
    } else {
        vis[b] = 1; int tmp = tim[bl[b]];
        for (int i = l; i <= r; i++) ret += min(m[i], k[i] * (now - tmp)), s[i] = 0, tim[i] = now;
        for (int i = bl[b]; i < l; i++) tim[i] = tmp, s[i] = 0;
        for (int i = r + 1; i <= br[b]; i++) tim[i] = tmp, s[i] = 0;
        return ret;
    }
}
int query(int t, int l, int r) {
    int p = bid[l], q = bid[r], ret = 0;
    if (p == q) return modify(p, l, r, t);
    ret = modify(p, l, br[p], t) + modify(q, bl[q], r, t);
    for (int i = p + 1; i <= q - 1; i++)
        if (vis[i] == 0) ret += f[i][min(t - tim[bl[i]], N)], tim[bl[i]] = t;
        else {
            for (int j = bl[i]; j <= br[i]; j++) ret += min(m[j], s[j] + k[j] * (t - tim[j]));
            tim[bl[i]] = t, vis[i] = 0;
        }
    return ret;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 1; i <= n; i++) fr(s[i], m[i], k[i]);
    Init();
    for (int q = fr(), t, l, r; q--;) fr(t, l, r), printf("%lld\n", query(t, l, r));
    return 0;
}