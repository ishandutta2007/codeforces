/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
 
void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
const int N = 50;
 
int a[N + 10];
 
int cmin(int a, int b) { return a < b ? a : b; }
int cmax(int a, int b) { return a > b ? a : b; }
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr(), ans = 0;
        for (int i = 1; i <= n; i++) fr(a[i]);
        for (int i = 1; i < n; i++) {
            double tmp = 1.0 * cmax(a[i], a[i + 1]) / cmin(a[i], a[i + 1]);
            if (tmp > 2.0) {
                int l = cmin(a[i], a[i + 1]);
                int r = cmax(a[i], a[i + 1]);
                while (l * 2 < r) {
                    l *= 2;
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}