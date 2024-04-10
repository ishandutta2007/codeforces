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

const int N = 4e5, LOGN = 19;

int n, q, a[N + 10], f[N + 10][LOGN + 10], lg2[N + 10];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void Init() {
    lg2[1] = 0;
    for (int i = 2; i <= N; i++) lg2[i] = lg2[i / 2] + 1;
}

int qgcd(int l, int r) {
    int s = lg2[r - l + 1];
    return gcd(f[l][s], f[r - (1 << s) + 1][s]);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    Init();
    for (int T = fr(); T--;) {
        int n = fr(), GCD = 0, ans = 0, flag = 1;
        for (int i = 1; i <= n; i++) fr(a[i]), GCD = gcd(GCD, a[i]);
        for (int i = 1; i <= n; i++) a[i] /= GCD, a[i + n] = a[i];
        for (int i = 1; i <= n; i++)
            if (a[i] != a[1]) flag = 0;
        if (flag) {
            puts("0");
            continue;
        }
        n <<= 1;
        for (int i = 1; i <= n; i++) f[i][0] = a[i];
        for (int j = 1; j <= lg2[n]; j++)
            for (int i = 1; i + (1 << (j - 1)) <= n; i++) f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        for (int l = 1, r = 1; r <= n; r++) {
            while (qgcd(l, r) == 1 && l <= r) l++;
            ans = max(ans, r - l + 1);
        }
        printf("%d\n", ans);
        cat:;
    }
    return 0;
}