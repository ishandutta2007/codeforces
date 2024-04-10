
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
 
const int N = 1e2;
 
int h[N + 10];
 
struct OI {
    int RP, score;
} NOIWC2021, FJOI2021;
 
int main() {
    NOIWC2021.RP++, NOIWC2021.score++, FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr(), k = fr(), pos = 0;
        for (int i = 1; i <= n; i++) fr(h[i]);
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == n) {
                    puts("-1");
                    goto cat;
                }
                if (h[j] < h[j + 1]) {
                    h[j]++, pos = j;
                    break;
                }
            }
        }
        printf("%d\n", pos);
    cat:;
    }
    return 0;
}