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

const int N = 2e5, M = 60, S = 1 << 15;

int n, m, p, ans, anss, a[N + 10], f[S + 10], arr[M + 10], cnt[S + 10];
char str[N + 10];

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    srand(time(0)), fr(n), fr(m), fr(p);
    for (int i = 1; i <= S; i++) cnt[i] = cnt[i >> 1] + (i & 1);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        for (int j = 0; j < m; j++)
            if (str[j] == '1') a[i] |= 1ll << j;
    }
    for (int T = 0; T < 60; T++) {
        int x = rnd() % n + 1, tot = 0;
        for (int i = 0; i < m; i++)
            if ((a[x] >> i) & 1) arr[tot++] = i;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            int tmp = 0;
            for (int j = 0; j < tot; j++)
                if ((a[i] >> arr[j]) & 1) tmp |= 1ll << j;
            f[tmp]++;
        }
        for (int i = tot - 1; ~i; i--)
            for (int j = (1 << tot) - 1; ~j; j--)
                if (((j >> i) & 1) == 0) f[j] += f[j ^ (1ll << i)];
        for (int i = 0; i < (1 << tot); i++)
            if (f[i] * 2 >= n && cnt[i] > ans) {
                ans = cnt[i], anss = 0;
                for (int j = 0; j < tot; j++)
                    if ((i >> j) & 1) anss |= 1ll << arr[j];
            }
    }
    for (int i = 0; i < m; i++) printf("%lld", (anss >> i) & 1);
    return 0;
}