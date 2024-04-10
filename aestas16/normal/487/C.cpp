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
int fr() { int a; return fr(a), a; }

const int N = 1e5;

int n, ans[N + 10];

int qpow(int a, int b, int P) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

void work() {
    fr(n);
    if (n == 4) return puts("YES\n1\n3\n2\n4"), void();
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return puts("NO"), void();
    ans[1] = 1;
    for (int i = 2; i < n; i++) ans[i] = i * qpow(i - 1, n - 2, n) % n;
    ans[n] = n;
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    work();
    return 0;
}