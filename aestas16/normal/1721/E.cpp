#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) (ch == '-') && (f = 1);
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    f && (a = -a);
}
template <class T, class ...Y> void fr(T &a, Y &...b) { fr(a), fr(b...); }
int fr() { int a; return fr(a), a; }

const int N = 2e6;

char str[N + 10], T[N + 10];
int n, pos, kmp[N + 10];
map<unsigned long long, int> H;

struct OI {
    int RP, score;
} CSPS2022, NOIP2022;

signed main() {
    CSPS2022.RP++, CSPS2022.score++, NOIP2022.RP++, NOIP2022.score++;
    scanf("%s", str + 1), n = strlen(str + 1);
    int j = 0;
    for (int i = 2; i <= n; i++) {
        while (j && str[i] != str[j + 1]) j = kmp[j];
        if (str[i] == str[j + 1]) j++;
        kmp[i] = j;
    }
    pos = j;
    for (int _ = fr(); _--;) {
        scanf("%s", T + 1);
        int m = strlen(T + 1), f = 1;
        for (int i = 1; i <= m; i++) str[n + i] = T[i];
        str[n + m + 1] = 0, j = pos;
        unsigned long long hsh = 0;
        for (int i = n + 1; i <= n + m; i++) {
            hsh = hsh * 29 + (str[i] - 'a' + 1);
            if (f && H.count(hsh)) { kmp[i] = j = H[hsh]; continue; }
            else f = 0;
            while (j && str[i] != str[j + 1]) j = kmp[j];
            if (str[i] == str[j + 1]) j++;
            kmp[i] = H[hsh] = j;
        }
        for (int i = n + 1; i <= n + m; i++) printf("%d ", kmp[i]);
        puts("");
    }
    return 0;
}