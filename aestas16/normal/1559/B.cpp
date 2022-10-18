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

const int N = 1e2;

char str[N + 10], ans[N + 10];
const char f[] = {'R', 'B'};

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    for (int _ = fr(); _--;) {
        int n = fr();
        scanf("%s", str + 1);
        int lst = 0;
        for (int i = 1; i <= n; i++) {
            if (str[i] == '?') ans[i] = f[lst];
            else if (str[i] == 'R') lst = 0, ans[i] = str[i];
            else lst = 1, ans[i] = str[i];
            lst ^= 1;
        }
        int tot1 = 0;
        for (int i = 2; i <= n; i++)
            if (ans[i] == ans[i - 1]) tot1++;
        lst = 1;
        for (int i = 1; i <= n; i++) {
            if (str[i] == '?') ans[i] = f[lst];
            else if (str[i] == 'R') lst = 0, ans[i] = str[i];
            else lst = 1, ans[i] = str[i];
            lst ^= 1;
        }
        int tot2 = 0;
        for (int i = 2; i <= n; i++)
            if (ans[i] == ans[i - 1]) tot2++;
        if (tot2 < tot1) {
            lst = 1;
            for (int i = 1; i <= n; i++) {
                if (str[i] == '?') putchar(f[lst]);
                else if (str[i] == 'R') lst = 0, putchar('R');
                else lst = 1, putchar('B');
                lst ^= 1;
            }
        } else {
            lst = 0;
            for (int i = 1; i <= n; i++) {
                if (str[i] == '?') putchar(f[lst]);
                else if (str[i] == 'R') lst = 0, putchar('R');
                else lst = 1, putchar('B');
                lst ^= 1;
            }
        }
        puts("");
    }
    return 0;
}