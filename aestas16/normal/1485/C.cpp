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
 
int cmin(int a, int b) {
    return a < b ? a : b;
}
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int a = fr(), b = fr(), mid = sqrt(a + 1), ans;
        if (mid > b) ans = b * (b - 1) / 2;
        else {
            ans = mid * (mid - 1) / 2;
            int up = cmin(a, b);
            for (int i = mid + 1; i <= up; i++) {
                int tmp = a / (i + 1);
                if (tmp == 0) break;
                int r = cmin(b, cmin(a, a / tmp - 1));
                ans += (r - i + 1) * (a / (i + 1));
                i = r;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}