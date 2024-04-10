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
        for (int i = 1; i <= n; i++) fr(a[i]), ans += abs(a[i] - a[i - 1]);
        ans += a[n], a[n + 1] = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans -= a[i] - max(a[i - 1], a[i + 1]);
        printf("%lld\n", ans);
    }
    return 0;
}