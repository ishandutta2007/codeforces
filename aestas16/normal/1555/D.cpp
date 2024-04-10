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

const int N = 2e5;

char str[N + 10], c[5];
int f[N + 10][10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    int n, m;
    fr(n, m), scanf("%s", str + 1);
    c[1] = 'a', c[2] = 'b', c[3] = 'c';
    int tot = 0;
    do {
        for (int i = 1; i <= n; i++){
            f[i][tot] = f[i - 1][tot];
            if (str[i] != c[(i - 1) % 3 + 1]) f[i][tot]++;}
        tot++;
    } while (next_permutation(c + 1, c + 4));
    while (m--) {
        int l = fr(), r = fr();
        int ans = 2e9;
        for (int i = 0; i <= 5; i++) ans = min(ans, f[r][i] - f[l - 1][i]);
        printf("%d\n", ans);
    }
    return 0;
}