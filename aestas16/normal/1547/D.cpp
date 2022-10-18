/*
     []
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

const int N = 2e5, S = 30;

int n, a[N + 10], b[N + 10], f[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        fr(n);
        for (int i = 1; i <= n; i++) fr(a[i]), b[i] = 0;
        for (int i = 1; i <= n; f[i] = a[i] ^ b[i], i++)
            for (int j = 0; j <= S; j++)
                if ((((a[i] >> j) & 1) == 0) && ((f[i - 1] >> j) & 1)) b[i] += (1 << j);
        for (int i = 1; i <= n; i++) printf("%d ", b[i]);
        puts("");
    }
    return 0;
}