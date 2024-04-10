/*
    I will never forget it.
*/
 
// 392699
 
#include <cmath>
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
 
int cmin(int a, int b) { return a < b ? a : b; }
 
int work(int a, int b) {
    int res = 0;
    while (a) a /= b, res++;
    return res;
}
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int a = fr(), b = fr(), ans = 64;
        for (int i = b == 1 ? 1 : 0; i <= 64; i++) {
            int tmp = work(a, b + i);
//            printf("i = %d tmp = %d\n", i, tmp);
            ans = cmin(ans, tmp + i);
        }
        printf("%d\n", ans);
    }
    return 0;
}