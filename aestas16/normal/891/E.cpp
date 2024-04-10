#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 5e3, P = 1e9 + 7;

int n, k, ans, a[N + 10], f[N + 10];

int qpow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, k), f[0] = 1;
    for (int i = 1; i <= n; i++) {
        fr(a[i]);
        for (int j = i; j; j--) f[j] = (f[j] * a[i] - f[j - 1] + P) % P;
        f[0] = f[0] * a[i] % P;
    }
    for (int i = 0, tmp = 1, inv = qpow(n, P - 2); i <= n; i++) ans = (ans + f[i] * tmp) % P, tmp = tmp * (k - i) % P * inv % P;
    return printf("%lld\n", (f[0] - ans + P) % P), 0;
}