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
        int n = fr();
        if (n == 1) {
            puts("z");
            continue;
        }
        if ((n & 1) == 0) {
            for (int i = 1; i < (n >> 1); i++) putchar('z');
            putchar('y');
            for (int i = 1; i <= (n >> 1); i++) putchar('z');
        } else {
            for (int i = 1; i < (n >> 1); i++) putchar('z');
            putchar('y'), putchar('x');
            for (int i = 1; i <= (n >> 1); i++) putchar('z');
        }
        puts("");
    }
    return 0;
}