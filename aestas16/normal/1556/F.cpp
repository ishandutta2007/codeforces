// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 4e6, P = 1e9 + 7;

int n, ans, a[20], f[20000], inv[N + 10];
int arr1[20], arr2[20];

void Init() {
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = (P - P / i) * inv[P % i] % P;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    Init(), fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = 1; i < (1 << n); i++) {
        f[i] = 1;
        for (int j = (i - 1) & i; j; j = (j - 1) & i) {
            int k = i ^ j;
            arr1[0] = arr2[0] = 0;
            for (int I = 1; I <= n; I++) {
                if (j & (1 << (I - 1))) arr1[++arr1[0]] = I;
                if (k & (1 << (I - 1))) arr2[++arr2[0]] = I;
            }
            int ret = 1;
            for (int I = 1; I <= arr1[0]; I++)
                for (int J = 1; J <= arr2[0]; J++) ret = ret * a[arr1[I]] % P * inv[a[arr1[I]] + a[arr2[J]]] % P;
            f[i] = (f[i] - ret * f[j] % P + P) % P;
        }
    }
    for (int i = 1; i < (1 << n); i++) {
        arr1[0] = arr2[0] = 0;
        for (int I = 1; I <= n; I++)
            if (i & (1 << (I - 1))) arr1[++arr1[0]] = I;
            else arr2[++arr2[0]] = I;
        int ret = 1;
        for (int I = 1; I <= arr1[0]; I++)
            for (int J = 1; J <= arr2[0]; J++) ret = ret * a[arr1[I]] % P * inv[a[arr1[I]] + a[arr2[J]]] % P;
        ans = (ans + ret * f[i] % P * arr1[0] % P) % P;
    }
    printf("%lld\n", ans);
    return 0;
}