/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
#include <cstring>
 
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
 
const int N = 1e5;
 
int a[N + 10], b[N + 10], c[N + 10], f[N + 10];
 
int cmax(int a, int b) { return a > b ? a : b; }
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        memset(f, 0, sizeof(f));
        int n = fr(), ans = 0;
        for (int i = 1; i <= n; i++) fr(c[i]);
        for (int i = 1; i <= n; i++) fr(a[i]);
        for (int i = 1; i <= n; i++) {
            fr(b[i]);
            if (b[i] < a[i]) {
                int t = a[i];
                a[i] = b[i], b[i] = t;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (i != 2 && a[i] != b[i]) f[i] = cmax(f[i], f[i - 1] + c[i - 1] - (b[i] - a[i] - 1));
            f[i] = cmax(f[i], b[i] - a[i] + 1), ans = cmax(ans, f[i] + c[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}