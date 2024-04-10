// 392699

#include <bits/stdc++.h>

#define int long long

#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

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

int a[N + 10], b[N + 10], psum[N + 10], ssum[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr();
        ssum[n + 1] = 0;
        for (int i = 1; i <= n; i++) fr(a[i]);
        for (int i = 1; i <= n; i++) fr(b[i]), psum[i] = psum[i - 1] + b[i];
        for (int i = n; i; i--) ssum[i] = ssum[i + 1] + a[i];
        int ans = 1e18;
        for (int i = 1; i <= n; i++) ans = min(ans, max(psum[i - 1], ssum[i + 1]));
        printf("%lld\n", ans);
    }
    return 0;
}