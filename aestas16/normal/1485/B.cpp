/*
    I will never forget it.
*/

// 392699

#include <cmath>
#include <cstdio>

#define int long long

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5;

int a[N + 10], b[N + 10], sum[N + 10];

struct OI {
    int RP, score;
} FJOI2021;

signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int n = fr(), q = fr(), k = fr();
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = 2; i < n; i++) b[i] = a[i + 1] - a[i - 1] - 1;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i];
    for (int i = 1; i <= q; i++) {
        int l = fr(), r = fr(), ans = 0;
        if (l == r) ans = k - 1;
        else ans = a[l + 1] - r + l - 1 + k - a[r - 1] + sum[r - 1] - sum[l] - 1;
        printf("%lld\n", ans);
    }
    return 0;
}