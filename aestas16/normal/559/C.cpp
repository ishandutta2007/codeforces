/*
     []
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e6, S = 2e3, P = 1e9 + 7;

int n, m, s, full, frac[N + 10], ifrac[N + 10], f[S + 10];

struct Node {
    int x, y;
    bool operator < (const Node &rhs) const {
        if (x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
} a[S + 10];

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
    fr(n), fr(m), fr(s), InitC();
    for (int i = 1; i <= s; i++) fr(a[i].x), fr(a[i].y);
    a[s + 1] = (Node){n, m}, sort(a + 1, a + 1 + s);
    for (int i = 1; i <= s + 1; i++) {
        f[i] = C(a[i].x + a[i].y - 2, a[i].x - 1);
        for (int j = 1; j < i; j++)
            if (a[i].x >= a[j].x && a[i].y >= a[j].y) f[i] = (f[i] - f[j] * C(a[i].x + a[i].y - a[j].x - a[j].y, a[i].x - a[j].x) % P + P) % P;
    }
    printf("%lld\n", f[s + 1]);
    return 0;
}