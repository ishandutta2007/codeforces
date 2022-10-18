/*
    I will never forget it.
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

const int N = 5e2, P = 998244353;

int n, ans, a[N + 10], f[N + 10][N + 10];
char str[N + 10][5];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
        if (str[i][1] == '+') fr(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (str[i][1] == '-') continue;
        memset(f, 0, sizeof(f)), f[0][0] = 1;
        for (int j = 1; j < i; j++) {
            if (str[j][1] == '-') {
                for (int k = 0; k <= j; k++) f[j][k] = f[j - 1][k];
                for (int k = 0; k <= j; k++) f[j][k] = (f[j][k] + f[j - 1][k + 1]) % P;
                f[j][0] = (f[j][0] + f[j - 1][0]) % P;
            } else {
                if (a[j] <= a[i]) {
                    for (int k = 0; k <= j; k++) f[j][k] = f[j - 1][k];
                    for (int k = 1; k <= j; k++) f[j][k] = (f[j][k] + f[j - 1][k - 1]) % P;
                } else
                    for (int k = 0; k <= j; k++) f[j][k] = f[j - 1][k] * 2 % P;
            }
        }
        for (int j = 0; j <= n; j++) f[i][j] = f[i - 1][j];
        for (int j = i + 1; j <= n; j++) {
            if (str[j][1] == '-') {
                for (int k = 0; k <= j; k++) f[j][k] = f[j - 1][k];
                for (int k = 0; k <= j; k++) f[j][k] = (f[j][k] + f[j - 1][k + 1]) % P;
            } else {
                if (a[j] < a[i]) {
                    for (int k = 0; k <= j; k++) f[j][k] = f[j - 1][k];
                    for (int k = 1; k <= j; k++) f[j][k] = (f[j][k] + f[j - 1][k - 1]) % P;
                } else
                    for (int k = 0; k <= j; k++) f[j][k] = f[j - 1][k] * 2 % P;
            }
        }
        int tmp = 0;
        for (int j = 0; j <= n; j++) tmp = (tmp + f[n][j]) % P;
        ans = (ans + tmp * a[i] % P) % P;
    }
    printf("%lld\n", ans);
    return 0;
}