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
        int n = fr(), k = fr(), ans = 0x7f7f7f7f, tmp = 0;
        if (n > k) {
            puts("0");
            goto cat;
        }
        for (int i = 30; ~i; i--) {
            if ((n & (1 << i)) == 0) {
                if ((k & (1 << i))) {
                    tmp |= (1 << i);
                    if ((n ^ tmp) > k) {
                        ans = min(ans, tmp);
                        break;
                    }
                } else ans = min(ans, tmp | (1 << i));
            }
        }
        printf("%d\n", ans);
        cat:;
    }
    return 0;
}