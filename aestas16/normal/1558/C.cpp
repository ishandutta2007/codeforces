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
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2021;

int a[N + 10], ans[N * 5 + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    for (int _ = fr(); _--;) {
        int n = fr();
        ans[0] = 0;
        for (int i = 1; i <= n; i++) {
            fr(a[i]);
        }
        for (int i = 1; i <= n; i++)
            if (a[i] % 2 == 0 && i % 2 == 1) {
                puts("-1");
                goto cat;
            }
        for (int i = n; i >= 3; i -= 2) {
            int p = 1;
            for (int j = 1; j <= i; j++)
                if (a[j] == i) {
                    p = j;
                    break;
                }
            ans[++ans[0]] = p, reverse(a + 1, a + p + 1);
            for (int j = 1; j <= i; j++)
                if (a[j] == i - 1) {
                    p = j - 1;
                    break;
                }
            ans[++ans[0]] = p, reverse(a + 1, a + p + 1);
            p += 2, ans[++ans[0]] = p, reverse(a + 1, a + p + 1);
            p = 3, ans[++ans[0]] = p, reverse(a + 1, a + p + 1);
            p = i, ans[++ans[0]] = p, reverse(a + 1, a + p + 1);
        }
        printf("%d\n", ans[0]);
        for (int i = 1; i <= ans[0]; i++) printf("%d%c", ans[i], " \n"[i == ans[0]]);
        cat:;
    }
    return 0;
}