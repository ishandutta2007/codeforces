/*
    I will never forget it.
*/
 
// 392699
 
#include <cmath>
#include <cstdio>
 
#define int long long
 
void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
const int N = 1e3;
 
int p[N + 10], sum[N + 10];
 
int cmax(int a, int b) { return a > b ? a : b; }
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr(), k = fr(), ans = 0;
        for (int i = 1; i <= n; i++) fr(p[i]), sum[i] = sum[i - 1] + p[i];
        for (int i = 2; i <= n; i++) {
            if (sum[i - 1] * k < 100 * p[i]) {
                int tmp = ceil(p[i] * 100.0 / k);
                ans = cmax(ans, tmp - sum[i - 1]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}