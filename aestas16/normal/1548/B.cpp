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

const int N = 4e5;

int a[N + 10], b[N + 10], lg2[N + 10], f[N + 10][20];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void Init() {
    lg2[1] = 0;
    for (int i = 2; i <= N; i++) lg2[i] = lg2[i >> 1] + 1;
}

int qgcd(int l, int r) {
    int s = lg2[r - l + 1];
    return gcd(f[l][s], f[r - (1 << s) + 1][s]);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    Init();
    for (int T = fr(); T--;) {
        int n = fr(), ans = 0;
        for (int i = 1; i <= n; i++) fr(a[i]);
        if (n == 1) {
            puts("1");
            continue;
        }
        for (int i = 1; i < n; i++) b[i] = abs(a[i + 1] - a[i]);
        for (int i = 1; i < n; i++) f[i][0] = b[i];
        for (int j = 1; j <= lg2[n - 1]; j++)
            for (int i = 1; i + (1 << (j - 1)) < n; i++) f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        for (int l = 1, r = 1; r < n; l++) {
            if (r < l) r = l;
            while (qgcd(l, r) != 1 && r < n) r++;
            // printf("%d %d\n", l, r);
            ans = max(ans, r - l + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
//