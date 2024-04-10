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

const int N = 5e2;

char s[N + 10], t[(N << 1) + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        scanf("%s%s", s + 1, t + 1);
        int n = strlen(s + 1), m = strlen(t + 1), f = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) {
                if (j - i + 1 > m) break;
                if (s[j] != t[j - i + 1]) break;
                if (2 * j - i >= m && j - i + 1 == m) {
                    f = 1;
                    break;
                }
                for (int k = j - 1; k; k--) {
                    if (s[k] != t[2 * j - (i - 1) - k]) break;
                    if (2 * j - (i - 1) - k == m) {
                        f = 1;
                        break;
                    }
                }
            }
        if (f) puts("YES");
        else puts("NO");
        cat:;
    }
    return 0;
}