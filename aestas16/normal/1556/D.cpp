// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e4;

int f[N + 10], a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    int n = fr(), k = fr();
    for (int i = 2; i <= n; i++) {
        printf("and 1 %d\n", i);
        fflush(stdout);
        int x = fr();
        printf("or 1 %d\n", i);
        fflush(stdout);
        int y = fr();
        f[i] = x + y;
    }
    int p;
    printf("and 2 3\n");
    fflush(stdout);
    int x = fr();
    printf("or 2 3\n");
    fflush(stdout);
    int y = fr();
    p = x + y;
    a[1] = (f[2] + f[3] - p) >> 1;
    for (int i = 2; i <= n; i++) a[i] = f[i] - a[1];
    sort(a + 1, a + n + 1);
    printf("finish %d\n", a[k]), fflush(stdout);
    return 0;
}