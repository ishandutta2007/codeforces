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

const int N = 1e3;

int a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    int n = fr(), ans = 0;
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = 1; i <= n; i += 2) {
        int tmp1 = 0, tmp2 = 0;
        for (int j = i + 1; j <= n; j++) {
            if ((j & 1) == 0) {
                ans += max(0ll, min(a[i] - tmp1, a[j] - tmp2) + (tmp1 != 0));
                int tmp = min(tmp2, a[j]);
                tmp2 -= tmp, tmp1 += a[j] - tmp;
            } else if (j & 1) tmp2 += a[j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}