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
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr(), k = fr();
        if (n % 2) {
            // k++;
            k--;
            int tmpk = k / ((n - 1) / 2);
            k += tmpk + 1;
        }
        printf("%d\n", (k - 1) % n + 1);
    }
    return 0;
}