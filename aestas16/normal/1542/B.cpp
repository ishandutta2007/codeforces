/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

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

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), a = fr(), b = fr();
        if (a == 1) puts((n - 1) % b == 0 ? "Yes" : "No");
        else {
            for (int i = 1; i <= n; i *= a)
                if ((n - i) % b == 0) {
                    puts("Yes");
                    goto cat;
                }
            puts("No");
            cat:;
        }
    }
    return 0;
}