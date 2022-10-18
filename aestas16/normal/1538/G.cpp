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

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int x = fr(), y = fr(), a = fr(), b = fr();
        if (x > y) swap(x, y);
        if (a > b) swap(a, b);
        if (a == b) {
            printf("%lld\n", min(x / a, y / b));
            continue;
        }
        int tmp = min((y - x) / (b - a), min(x / a, y / b));
        x -= tmp * a, y -= tmp * b;
        int ans = tmp + min(x, y) / (a + b) * 2;
        if (x >= a && y >= b) x -= a, y -= b, ans = max(ans, tmp + 1 + min(x, y) / (a + b) * 2);
        printf("%lld\n", ans);
    }
    return 0;
}