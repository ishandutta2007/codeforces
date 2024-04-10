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

const int N = 1e6, P = 998244353;

int n, ptot, tot, ans, a[N + 10], pnum[N / 10 + 10], mu[N + 10], arr[N + 10];
bool isnp[N + 10];

int qpow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

void Init() {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (isnp[i] == 0) pnum[++ptot] = i, mu[i] = -1;
        for (int j = 1; j <= ptot && i * pnum[j] <= N; j++) {
            isnp[i * pnum[j]] = 1;
            if (i % pnum[j]) mu[i * pnum[j]] = -mu[i];
            else break;
        }
    }
}

int solve(int x) {
    int sum1 = 0, sum2 = 0, tmp;
    for (int i = 1; i <= tot; i++) sum1 = (sum1 + a[arr[i]] * arr[i] % P) % P, sum2 = (sum2 + a[arr[i]] * arr[i] % P * arr[i] % P) % P;
    tmp = sum2 * qpow(2, x - 2) % P * ((x - 1 + P) % P) % P, sum1 = (sum1 * sum1 % P - sum2 + P) % P;
    if (x >= 3) sum1 = sum1 * qpow(2, x - 3) % P * (x % P) % P;
    return (sum1 + tmp) % P;
}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n), Init();
    for (int i = 1, x, y; i <= n; i++) fr(x, y), a[x] = y;
    for (int i = 1; i <= N; i++) {
        int tmp = 0; tot = 0;
        for (int j = i; j <= N; j += i)
            if (a[j]) tmp += a[j], arr[++tot] = j;
        if (tmp >= 2) ans = (ans + mu[i] * solve(tmp) % P + P) % P;
    }
    printf("%lld\n", ans);
    return 0;
}