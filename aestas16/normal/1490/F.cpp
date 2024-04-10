/*
    I will never forget it.
*/
 
// 392699
 
#include <algorithm>
#include <cstdio>
#include <map>
 
using std::map;
 
void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
const int N = 2e5;
 
map<int, int> cnt;
map<int, bool> vis;
int a[N + 10], acnt[N + 10];
 
int cmin(int a, int b) { return a < b ? a : b; }
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr(), tot = 0, ans = 999392699;
        for (int i = 1; i <= n; i++) fr(a[i]), cnt[a[i]]++;
        for (int i = 1; i <= n; i++) {
            if (vis[a[i]] == 0) acnt[++tot] = cnt[a[i]], vis[a[i]] = 1;
        }
        std::sort(acnt + 1, acnt + 1 + tot);
        // printf("tot=%d\n", tot);
        int sum = 0;
        for (int i = 1; i <= tot; i++) {
            ans = cmin(ans, n - (tot - i + 1) * acnt[i]);
            sum += acnt[i];
        }
        for (int i = 1; i <= n; i++) cnt[a[i]] = 0, vis[a[i]] = 0;
        printf("%d\n", ans);
    }
    return 0;
}