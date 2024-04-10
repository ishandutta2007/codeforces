/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

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

const int N = 1e5;

int n, xsum, a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]), xsum ^= a[i];
    if (n % 2 == 0) {
        if (xsum) return puts("NO"), 0;
        n--;
    }
    puts("YES"), printf("%d\n", n - 1);
    if (n - 1) {
        for (int i = 1; i <= n - 2; i += 2) printf("%d %d %d\n", i, i + 1, i + 2);
        for (int i = 1; i <= n - 2; i += 2) printf("%d %d %d\n", n, i, i + 1);
    }
    return 0;
}