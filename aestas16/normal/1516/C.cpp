/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5, INF = 0x7f7f7f7f;

int a[N + 10], f[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    int n = fr(), Min = INF, sum = 0;
    for (int i = 1; i <= n; i++) fr(a[i]), Min = min(Min, a[i] & (-a[i]));
    for (int i = 1; i <= n; i++) a[i] /= Min, sum += a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = sum; j >= a[i]; j--) f[j] |= f[j - a[i]];
    if ((sum & 1) || f[sum >> 1] == 0) return puts("0"), 0;
    for (int i = 1; i <= n; i++)
        if (a[i] & 1) return printf("1\n%d\n", i), 0;
    return 0;
}