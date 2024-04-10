// 392699

#include <bits/stdc++.h>

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

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), k = fr(), xa = fr(), ya = fr(), xb = fr(), yb = fr(), w = fr(), h = fr();
        int ans = 2e9;
        if (yb - ya + h <= k) ans = min(ans, min(h - ya, h - k + yb));
        if (xb - xa + w <= n) ans = min(ans, min(w - xa, w - n + xb));
        ans = max(ans, 0), printf("%d.00000000\n", ans == 2e9 ? -1 : ans);
    }
    return 0;
}