/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 4e5, INF = 0x7f7f7f7f;

int a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), Min = INF, Minpos = 2;
        for (int i = 1; i <= n; i++) fr(a[i]);
        sort(a + 1, a + 1 + n);
        if (n == 2) {
            printf("%d %d\n", a[1], a[2]);
            continue;
        }
        for (int i = 2; i <= n; i++)
            if (a[i] - a[i - 1] < Min) Min = a[i] - a[i - 1], Minpos = i;
        for (int i = Minpos; i <= n; i++) printf("%d ", a[i]);
        for (int i = 1; i < Minpos; i++) printf("%d ", a[i]);
        puts("");
    }
    return 0;
}