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

const int N = 5e5, P = 1e9 + 7;

int cnt[5];
char str[N + 10];

int qpow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), m = fr();
        cnt[0] = cnt[1] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", str + 1);
            for (int j = 1; j <= m; j++) cnt[str[j] == '0']++;
        }
        int ans = qpow(2, cnt[0]);
        if (cnt[1] == 0) ans = (ans - 1 + P) % P;
        printf("%lld\n", ans);
    }
    return 0;
}