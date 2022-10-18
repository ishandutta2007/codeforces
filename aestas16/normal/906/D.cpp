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

const int N = 1e5;

int n, m, q, l, r, a[N + 10];

map<int, int> ph;

int phi(int n) {
    int t = sqrt(n), res = n;
    for (int i = 2; i <= t; i++)
        if (n % i == 0) {
            res /= i, res *= (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) res /= n, res *= (n - 1);
    return res;
}

int qpow(int a, int b, int MOD) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
            if (res >= MOD) res = res % MOD + MOD;
        }
        a = a * a;
        if (a >= MOD) a = a % MOD + MOD;
        b >>= 1;
    }
    return res;
}

int dfs(int x, int p) {
    if (x == r + 1 || p == 1) return 1;
    int t = dfs(x + 1, ph[p]);
    return qpow(a[x], t, p);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n, m);
    int cur = m;
    while (cur != 1) ph[cur] = phi(cur), cur = ph[cur];
    ph[cur] = 1;
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (fr(q); q--;) {
        fr(l, r);
        printf("%lld\n", dfs(l, m) % m);
    }
    return 0;
}