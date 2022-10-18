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

const int N = 1e6, P = 998244353;

int n, cnt[N + 10], f[N + 10], sum[N + 10];

void Init() {
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i) cnt[j] = (cnt[j] + 1) % P;
    for (int i = 1; i <= N; i++) f[i] = (sum[i - 1] + cnt[i]) % P, sum[i] = (sum[i - 1] + f[i]) % P;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    Init();
    fr(n);
    printf("%lld\n", f[n]);
    return 0;
}