#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }
 
const int N = 1e5, A = 5e6;
 
int n, ans, a[N + 10], cnt[A + 10], sum[A + 10], f[A + 10];
 
struct OI {
    int RP, score;
} NOIP2021, FJOI2022;
 
signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]), cnt[a[i]]++;
    for (int i = 1; i <= A; i++)
        for (int j = i; j <= A; j += i) sum[i] += cnt[j];
    for (int i = A; i; i--) {
        f[i] = sum[i] * i;
        int tmp = 0;
        for (int j = i + i; j <= A; j += i) tmp = max(tmp, f[j] - sum[j] * i);
        f[i] += tmp;
        // printf("f[%lld] = %lld\n", i, f[i]);
    }
    printf("%lld\n", f[1]);
    return 0;
}