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

int a[20] = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

int f[2010];

int cnt(int x) {
    int ret = 0;
    while (x) x /= 10, ret++;
    return ret;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    f[11] = f[111] = f[1111] = 1;
    for (int i = 1; i <= 2000; i++)
        for (int j = 2; j <= 4; j++)
            if (i >= a[j]) f[i] |= f[i - a[j]];
    for (int T = fr(), x; T--;) {
        fr(x);
        if (x <= 2000) puts(f[x] ? "YES" : "NO");
        else puts("YES");
        // if (x % 100 == 0) puts("NO");
        // else if ((x % 100 - x % 10) == (x % 10) * 10) puts("YES");
        // else puts("NO");
    }
    return 0;
}