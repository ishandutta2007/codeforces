// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5;

int n, q, a[N + 10], b[N + 10], c[N + 10], lg2[N + 10], f[N + 10][20], g[N + 10][20];

void InitST() {
    for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    for (int i = 1; i <= n; i++) c[i] = f[i][0] = g[i][0] = b[i] - a[i];
    for (int j = 1; j <= lg2[n]; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]), g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
}

int qmin(int l, int r) {
    int s = lg2[r - l + 1];
    return min(f[l][s], f[r - (1 << s) + 1][s]);
}
int qmax(int l, int r) {
    int s = lg2[r - l + 1];
    return max(g[l][s], g[r - (1 << s) + 1][s]);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    n = fr(), q = fr();
    for (int i = 1; i <= n; i++) fr(a[i]), a[i] += a[i - 1];
    for (int i = 1; i <= n; i++) fr(b[i]), b[i] += b[i - 1];
    InitST();
    while (q--) {
        int l = fr(), r = fr();
        if (a[r] - a[l - 1] != b[r] - b[l - 1]) {
            puts("-1");
            continue;
        }
        int mn = qmin(l, r) - c[l - 1], mx = qmax(l, r) - c[l - 1];
        if (mn < 0) puts("-1");
        else printf("%lld\n", mx);
    }
    return 0;
}