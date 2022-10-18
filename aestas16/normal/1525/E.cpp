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

const int N = 20, M = 5e4, P = 998244353;

int n, m, ans, frac = 1, cnt[M + 10][N + 10], d[N + 10][M + 10];

int qpow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), fr(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) fr(d[i][j]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) cnt[i][j] += (d[k][i] > j);
    for (int i = 2; i <= n; i++) frac = frac * i % P;
    for (int i = 1; i <= m; i++) {
        int res = 1;
        for (int j = 1; j <= n; j++) {
            if (cnt[i][n - j + 1] - j + 1 <= 0) {
                res = 0;
                break;
            }
            res = res * (cnt[i][n - j + 1] - j + 1) % P;
        }
        ans = (ans + frac - res + P) % P;
    }
    return printf("%lld\n", ans * qpow(frac, P - 2) % P), 0;
}
/*
1 4 4 3 4
1 4 1 4 2
1 4 4 4 3

0 3 3 2 3
0 3 0 3 1
0 3 3 3 2

t: 
*/