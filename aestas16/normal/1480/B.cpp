
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
 
const int N = 1e5;
 
int a[N + 10], b[N + 10];
 
int cmax(int a, int b) { return a > b ? a : b; }
 
struct OI {
    int RP, score;
} NOIWC2021, FJOI2021;
 
signed main() {
    NOIWC2021.RP++, NOIWC2021.score++, FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int tot = 0, Max = 0, A = fr(), B = fr(), n = fr();
        for (int i = 1; i <= n; i++) fr(a[i]);
        for (int i = 1; i <= n; i++) fr(b[i]);
        for (int i = 1; i <= n; i++) {
            int tmp = b[i] / A;
            if (b[i] % A) tmp++;
            tot += tmp * a[i];
            Max = cmax(Max, a[i]);
        }
        if (B > tot - Max)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}