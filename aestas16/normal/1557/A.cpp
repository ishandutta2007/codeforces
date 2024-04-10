// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef Aestas16
    #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
    #define debug(...) 0
#endif

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5;

double sum[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr();
        double ans = -1e18;
        for (int i = 1; i <= n; i++) scanf("%lf", &sum[i]);
        sort(sum + 1, sum + 1 + n);
        for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
        for (int i = 1; i < n; i++) ans = max(ans, sum[i] / i + (sum[n] - sum[i]) / (n - i));
        printf("%.9lf\n", ans);
    }
    return 0;
}