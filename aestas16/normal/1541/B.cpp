/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 4e5;

int a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), ans = 0;
        for (int i = 1; i <= n; i++) fr(a[i]);
        for (int i = 1; i <= n; i++) {
            for (int k = a[i]; k <= n * 2; k += a[i]) {
                // k = a[i] * a[j] = i + j
                // j = k - i
                int j = k - i;
                if (j <= i || j > n) continue;
                if (a[i] * a[j] == k) ans++;
                // if (a[k] == i + j) ans++;
            }
        }
        for (int i = 1; i <= n; i++) a[i] = 0;
        printf("%lld\n", ans);
    }
    return 0;
}