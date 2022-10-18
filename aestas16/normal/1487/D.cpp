/*
    I will never forget it.
*/
 
// 392699
 
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
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr(), ans = 0;
        for (int i = 2; i <= n; i++) {
            int tmp = i * i;
            if ((i * i - 1) % 2) continue;
            if ((i * i - 1) / 2 > n) break;
            int b = (i * i - 1) / 2;
            if (i * i - b > n) continue;
            ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}