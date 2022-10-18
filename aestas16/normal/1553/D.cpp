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

const int N = 1e5;

char s[N + 10], t[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        scanf("%s%s", s + 1, t + 1);
        int n = strlen(s + 1), m = strlen(t + 1);
        while (1) {
            if (s[n] == t[m]) n--, m--;
            else n -= 2;
            if (n <= 0) break;
            if (m == 0) break;
        }
        if (m) puts("NO");
        else puts("YES");
    }
    return 0;
}