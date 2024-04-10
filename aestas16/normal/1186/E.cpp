#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e3;

char str[N + 10];
int n, m, _, a[N + 3][N + 3], sum[N + 3][N + 3];

int S(int x, int y) {
    int ret = (x * y - (x % n) * (y % m)) >> 1;
    if ((__builtin_popcountll(x / n) + __builtin_popcountll(y / m)) & 1) ret += (x % n) * (y % m) - sum[x % n][y % m];
    else ret += sum[x % n][y % m];
    return ret;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, m, _);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        for (int j = 1; j <= m; j++) a[i + n][j + m] = a[i][j] = str[j] - '0', a[i][j + m] = a[i + n][j] = a[i][j] ^ 1;
    }
    n <<= 1, m <<= 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    for (int X1, Y1, X2, Y2; _--;) fr(X1, Y1, X2, Y2), printf("%lld\n", S(X2, Y2) - S(X1 - 1, Y2) - S(X2, Y1 - 1) + S(X1 - 1, Y1 - 1));
    return 0;
}