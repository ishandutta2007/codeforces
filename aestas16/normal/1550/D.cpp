/*
     []
*/
 
// 392699
 
#include <bits/stdc++.h>
 
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
 
#define int long long
 
// using namespace std;
 
template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
const int N = 4e5, P = 1e9 + 7;
 
int frac[N + 10], ifrac[N + 10];
 
void InitC() {
    frac[0] = frac[1] = ifrac[0] = ifrac[1] = 1;
    for (int i = 2; i <= N; i++) ifrac[i] = (P - P / i) * ifrac[P % i] % P;
    for (int i = 2; i <= N; i++) frac[i] = frac[i - 1] * i % P, ifrac[i] = ifrac[i] * ifrac[i - 1] % P;
}
 
int C(int x, int y) {
    if (x < 0 || y < 0) return 0;
    return frac[x + y] * ifrac[y] % P * ifrac[x] % P;
}
 
struct OI {
    int RP, score;
} CSPS2021, NOIP2021;
 
signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    InitC();
    for (int T = fr(); T--;) {
        int ans = 0, n = fr(), l = fr(), r = fr(), dn = 0x7f7f7f7f, up = 0x7f7f7f7f, a, b, c, n2 = n / 2;
        for (int i = 1; i <= n; i++) {
            a = i - l, b = r - i, dn = min(dn, min(a, b)), up = min(up, max(a, b));
        }
        for (int i = dn + 1; i <= up; i++) {
            a = min(n, n - i - l + 1), b = min(n, r - i);
            if (a < 0) a = 0;
            if (b < 0) b = 0;
            c = min(a, min(b, r - 2 * i - l + 1));
            if (c < 0) c = 0;
            // printf("a = %lld b = %lld c = %lld\n", a, b, c);
            if (max(a - c, b - c) > max(n2, n - n2)) break;
            ans = (ans + C(n2 - a + c, n - n2 - b + c)) % P;
            if (n % 2) ans = (ans + C(n - n2 - a + c, n2 - b + c)) % P;
        }
        ans = (ans + dn * C(n2, n - n2) % P) % P;
        if (n % 2) ans = (ans + dn * C(n - n2, n2)) % P;
        printf("%lld\n", ans);
    }
    return 0;
}