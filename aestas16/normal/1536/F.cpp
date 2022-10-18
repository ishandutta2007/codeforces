/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e6, P = 1e9 + 7;

int n, ans, frac[N + 10], ifrac[N + 10];

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
	fr(n), InitC();
	for (int i = (n - 1) / 4 + 1; i * 2 <= n; i++) ans = (ans + 2 * n % P * frac[2 * i - 1] % P * C(2 * i, n - 2 * i) % P) % P;
    return printf("%lld\n", ans), 0;
}