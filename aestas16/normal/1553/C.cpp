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

const int N = 10;

int a[5], b[5];
char str[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        scanf("%s", str + 1), a[0] = a[1] = b[0] = b[1] = 0;
        for (int i = 1; i <= 10; i++) {
            if (str[i] == '1') a[i & 1]++;
            else if (str[i] == '?') b[i & 1]++;
            if (a[1] + b[1] - a[0] > (10 - i + 1) / 2) {
                printf("%d\n", i);
                goto cat;
            }
            if (a[0] + b[0] - a[1] > (10 - i) / 2) {
                printf("%d\n", i);
                goto cat;
            }
        }
        printf("%d\n", 10);
        cat:;
    }
    return 0;
}