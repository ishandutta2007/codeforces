#include <bits/stdc++.h>

using namespace std;

const int N = 4e5, P = 998244353, inv2 = (P + 1) / 2, inv3 = (P + 1) / 3;

char str[N + 10];
int n, nn, ans, S[N + 10], C[N + 10], cnt[N + 10], p2[N + 10], ip2[N + 10];

int sum1(int i) {
    return 1ll * (cnt[i] + 1) * (cnt[i] + 1) % P * p2[i] % P;
}
int sum2(int i) {
    return  (1ll * (cnt[i] + 1) * p2[2 * i]
          + 1ll * p2[2 * i + 1] * cnt[i] % P * (cnt[i] + 1)
          + 1ll * cnt[i] * (cnt[i] + 1) % P * (2 * cnt[i] + 1) % P * p2[2 * i + 1] % P * inv3) % P;
}

signed main() {
    scanf("%s", str + 1), n = strlen(str + 1), S[2] = C[2] = p2[0] = ip2[0] = 1;
    for (int i = 3; i <= n; i++) S[i] = ((6ll * S[i - 1] - 11ll * S[i - 2] + 6ll * S[i - 3]) % P + P) % P, C[i] = (S[i] - S[i - 1] + P) % P;
    for (int i = 1, x = 0; i <= n; i++) {
        x = (x * 2ll + (str[i] - '0')) % P, nn = x;
        if (str[i] == '1') cnt[n - i] = 1ll * (x - 1) * inv2 % P;
        else cnt[n - i] = (1ll * x * inv2 - 1 + P) % P;
    }
    for (int i = 1; i <= n * 2; i++) p2[i] = p2[i - 1] * 2ll % P, ip2[i] = 1ll * ip2[i - 1] * inv2 % P;
    for (int i = 0; i < n; i++) {
        int s1 = sum1(i), s2 = sum2(i), tmp = (1ll * s1 * S[i] + 1ll * (1ll * s2 * ip2[i] % P - s1 + P) % P * C[i + 1]) % P;
        ans = (ans + 1ll * (nn + 1) * (1ll * (cnt[i] + 1) * S[i] % P + (1ll * s1 * ip2[i] % P - (cnt[i] + 1) + P) % P * C[i + 1] % P) % P - tmp + P) % P;
    }
    printf("%lld\n", ans * 6ll % P);
    return 0;
}