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

const int N = 3e5, INF = 0x7f7f7f7f;

int n, a[N + 10], f[N + 10][2], p[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), k = fr();
        for (int i = 1; i <= k; i++) fr(a[i]);
        for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = p[i] = INF;
        for (int i = 1, x; i <= k; i++) fr(x), p[a[i]] = x;
        for (int i = 1; i <= n; i++)
            if (i == 1) f[i][0] = min(f[i][0], p[i]);
            else f[i][0] = min(f[i - 1][0] + 1, p[i]);
        for (int i = n; i; i--)
            if (i == n) f[i][1] = min(f[i][1], p[i]);
            else f[i][1] = min(f[i + 1][1] + 1, p[i]);
        for (int i = 1; i <= n; i++) f[i][0] = min(f[i][0], f[i][1]);
        for (int i = 1; i <= n; i++) printf("%d ", f[i][0]);
        puts("");
    }
    return 0;
}