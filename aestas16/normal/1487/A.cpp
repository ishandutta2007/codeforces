/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
#include <cstring>
 
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
 
int cnt[N + 10], a[N + 10];
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr();
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) fr(a[i]), cnt[a[i]]++;
        for (int i = 0; i <= N; i++)
            if (cnt[i]) {
                printf("%d\n", n - cnt[i]);
                goto cat;
            }
    cat:;
    }
    return 0;
}