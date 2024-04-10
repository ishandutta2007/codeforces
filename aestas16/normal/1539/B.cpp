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

const int N = 1e5;

char str[N + 10];
int sum[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    int n = fr(), q = fr();
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + str[i] - 'a' + 1;
    for (int i = 1; i <= q; i++) {
        int l = fr(), r = fr();
        printf("%lld\n", sum[r] - sum[l - 1]);
    }
    return 0;
}