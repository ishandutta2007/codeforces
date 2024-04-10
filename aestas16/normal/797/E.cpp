#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e5, M = 316;

int n, q, a[N + 10], f[N + 10][M + 10];

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = n; i; i--)
        for (int j = 1; j <= M; j++)
            if (i + a[i] + j > n) f[i][j] = 1;
            else f[i][j] = f[i + a[i] + j][j] + 1;
    for (int p, k, q = fr(); q--;) {
        fr(p, k);
        if (k <= M) printf("%d\n", f[p][k]);
        else {
            int ans = 0;
            while (p <= n) ans++, p = p + a[p] + k;
            printf("%d\n", ans);
        }
    }
    return 0;
}