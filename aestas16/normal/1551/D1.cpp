// 392699

#include <bits/stdc++.h>

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

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), m = fr(), k = fr();
        if (n & 1) {
            if (k < (m >> 1)) {
                puts("NO");
                goto cat;
            }
            k -= (m >> 1);
            if (k & 1) {
                puts("NO");
                goto cat;
            }
            puts("YES");
            goto cat;
        }
        if (m & 1) {
            int tmpk = n * m / 2 - k;
            if (tmpk < (n >> 1)) {
                puts("NO");
                goto cat;
            }
            tmpk -= (n >> 1);
            if (tmpk & 1) {
                puts("NO");
                goto cat;
            }
            puts("YES");
            goto cat;
        }
        if (k & 1) puts("NO");
        else puts("YES");
        cat:;
    }
    return 0;
}