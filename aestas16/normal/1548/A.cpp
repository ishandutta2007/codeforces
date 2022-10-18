// 392699

#include <bits/stdc++.h>

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

const int N = 2e5;

int deg[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    int n = fr(), m = fr(), ans = n, q;
    for (int i = 1, u, v; i <= m; i++) {
        fr(u, v);
        if (u > v) swap(u, v);
        deg[u]++;
        if (deg[u] == 1) ans--;
    }
    fr(q);
    for (int i = 1; i <= q; i++) {
        int opt = fr(), u, v;
        if (opt == 1) {
            fr(u, v);
            if (u > v) swap(u, v);
            deg[u]++;
            if (deg[u] == 1) ans--;
        } else if (opt == 2) {
            fr(u, v);
            if (u > v) swap(u, v);
            deg[u]--;
            if (deg[u] == 0) ans++;
        } else printf("%d\n", ans);
    }
    return 0;
}