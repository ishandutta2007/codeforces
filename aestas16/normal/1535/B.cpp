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

const int N = 2e3;

int n, a[N + 10], atot, b[N + 10], btot;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int ans = 0;
        fr(n), atot = btot = 0;
        for (int i = 1, x; i <= n; i++) {
            fr(x);
            if (x & 1) a[++atot] = x;
            else b[++btot] = x;
        }
        for (int i = 1; i <= btot; i++) a[++atot] = b[i];
        for (int i = 1; i <= atot; i++)
            for (int j = i + 1; j <= atot; j++)
                if (gcd(a[j], 2 * a[i]) > 1) ans++;
        printf("%d\n", ans);
    }
    return 0;
}