#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int P = 1e9 + 7;
const int nx[] = {-1, 0, 1, 0};
const int ny[] = {0, -1, 0, 1};

int R, ptot, a[10], f[8005][8005], arr[8005], ans[8005], id[105][105], tot;

inline bool chk(int x, int y) { return x * x + y * y <= R * R; }

int qpow(register int a, register int b) {
    register int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P) b & 1 ? ret = 1ll * ret * a % P : 0;
    return ret;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(R, a[0], a[1], a[2], a[3]), a[4] = qpow((a[0] + a[1] + a[2] + a[3]) % P, P - 2);
    for (register int i = 0; i < 4; i++) a[i] = 1ll * a[i] * a[4] % P;
    for (register int i = -R; i <= R; i++) for (register int j = -R; j <= R; j++) if (chk(i, j)) id[i + R][j + R] = ++tot;
    for (register int i = -R; i <= R; i++)
        for (register int j = -R; j <= R; j++)
            if (chk(i, j)) {
                ptot++, f[ptot][tot + 1] = f[ptot][id[i + R][j + R]] = 1;
                for (register int k = 0; k < 4; k++) {
                    register int x = i + nx[k], y = j + ny[k];
                    if (chk(x, y)) f[ptot][id[x + R][y + R]] = P - a[k];
                }
            }
    for (register int i = 1; i <= ptot; i++) {
        if (f[i][i] == 0) for (register int j = i + 1; j <= ptot; j++) if (f[j][i]) { swap(f[i], f[j]); break; }
        register int inv = qpow(f[i][i], P - 2), tmp = 0;
        for (register int j = i + 1; j <= ptot + 1; j++) if (f[i][j]) arr[++tmp] = j;
        for (register int j = i + 1; j <= ptot; j++) {
            if (f[j][i] == 0) continue;
            register int t = 1ll * f[j][i] * inv % P;
            for (register int k = 1; k <= tmp; k++) f[j][arr[k]] = (f[j][arr[k]] - 1ll * f[i][arr[k]] * t % P + P) % P;
        }
    }
    for (register int i = ptot; i; i--) {
        register int tmp = f[i][ptot + 1];
        for (register int j = i + 1; j <= ptot; j++) tmp = (tmp - 1ll * f[i][j] * ans[j] % P + P) % P;
        ans[i] = 1ll * tmp * qpow(f[i][i], P - 2) % P;
    }
    return printf("%d\n", ans[id[R][R]]), 0;
}