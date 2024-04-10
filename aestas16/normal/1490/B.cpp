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
 
const int N = 3e5;
 
int c[5];
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr(), tmp = n / 3, ans = 0;
        c[0] = c[1] = c[2] = 0;
        for (int i = 1, a; i <= n; i++) fr(a), c[a % 3]++;
        // printf("tmp:%d\n", tmp);
        if (c[0] > tmp) c[1] += c[0] - tmp, ans += c[0] - tmp, c[0] = tmp;
        if (c[1] > tmp) c[2] += c[1] - tmp, ans += c[1] - tmp, c[1] = tmp;
        if (c[2] > tmp) c[0] += c[2] - tmp, ans += c[2] - tmp, c[2] = tmp;
        if (c[0] > tmp) c[1] += c[0] - tmp, ans += c[0] - tmp, c[0] = tmp;
        if (c[1] > tmp) c[2] += c[1] - tmp, ans += c[1] - tmp, c[1] = tmp;
        printf("%d\n", ans);
    }
    return 0;
}