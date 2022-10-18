/*
    I will never forget it.
*/
 
// 392699
 
#include <algorithm>
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
 
const int N = 2e5;
 
int a[N + 10], b[N + 10];
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr();
        for (int i = 1; i <= n; i++) fr(a[i]), b[i] = a[i];
        std::sort(a + 1, a + 1 + n);
        int sum = a[1], mid = -1;
        for (int i = 2; i <= n; i++) {
            while (a[i] == a[i - 1]) sum += a[i++];
            if (sum < a[i]) mid = a[i - 1];
            sum += a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (b[i] > mid) ans++;
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++)
            if (b[i] > mid) printf("%lld ", i);
        puts("");
    }
    return 0;
}