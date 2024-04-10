/*
     []
*/

// 392699

#include <bits/stdc++.h>

#define int long long

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

const int N = 3e5, P = 998244353;

int frac[N + 10], ifrac[N + 10];
char str[N + 10];

void InitC() {
    frac[0] = frac[1] = ifrac[0] = ifrac[1] = 1;
    for (int i = 2; i <= N; i++) ifrac[i] = (P - P / i) * ifrac[P % i] % P;
    for (int i = 2; i <= N; i++) frac[i] = frac[i - 1] * i % P, ifrac[i] = ifrac[i] * ifrac[i - 1] % P;
}

int C(int x, int y) {
    if (y > x || x < 0 || y < 0) return 0;
    return frac[x] * ifrac[y] % P * ifrac[x - y] % P;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    InitC();
    for (int T = fr(); T--;) {
        int n = fr();
        scanf("%s", str + 1);
        int c1 = 0, c2 = 0, tot = 0;
        for (int i = 1; i <= n; i++)
            if (str[i] == '0') c2 += (tot % 2), tot = 0;
            else c1++, tot++;
        printf("%lld\n", C(n - c1 + (c1 - c2) / 2, (c1 - c2) / 2));
    }
    return 0;
}