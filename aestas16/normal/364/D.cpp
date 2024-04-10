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

const int N = 1e6;

int n, ans, f[N + 10], a[N + 10], d[N + 10];
map<int, bool> vis;

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    mt19937 rnd((unsigned long long)(new char));
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int _ = 1; _ <= 10; _++) {
        int x = a[rnd() % n + 1], tot = 0;
        if (vis[x]) continue; vis[x] = 1;
        for (int i = 1; i * i <= x; i++) if (x % i == 0) d[++tot] = i, (i * i != x) && (d[++tot] = x / i);
        sort(d + 1, d + 1 + tot);
        for (int i = 1; i <= tot; i++) f[i] = 0;
        for (int i = 1; i <= n; i++) f[lower_bound(d + 1, d + 1 + tot, __gcd(x, a[i])) - d]++;
        for (int i = 1; i <= tot; i++) if (f[i]) for (int j = 1; j < i; j++) if (d[i] % d[j] == 0) f[j] += f[i];
        for (int i = tot; i; i--) if (f[i] * 2 >= n) { ans = max(ans, d[i]); break; }
    }
    return printf("%lld\n", ans), 0;
}