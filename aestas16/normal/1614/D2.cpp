#include <bits/stdc++.h>
 
using namespace std;
 
template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }
 
const int N = 1e5, A = 2e7;
 
int n, a[N + 10], cnt[A + 10], ptot, pnum[A / 10 + 10];
long long ans, f[A + 10];
bool isnp[A + 10];
 
struct OI {
    int RP, score;
} NOIP2021, FJOI2022;
 
signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n), isnp[1] = 1;
    for (int i = 1; i <= n; i++) fr(a[i]), cnt[a[i]]++;
    for (int i = 2; i <= A; i++) {
        if (isnp[i] == 0) pnum[++ptot] = i;
        for (int j = 1; j <= ptot && pnum[j] * i <= A; j++) {
            isnp[i * pnum[j]] = 1;
            if (i % pnum[j] == 0) break;
        }
    }
    for (int i = 1; i <= ptot; i++)
        for (int j = A / pnum[i]; j; j--) cnt[j] += cnt[j * pnum[i]];
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= ptot && pnum[j] * i <= A; j++) f[i * pnum[j]] = max(f[i * pnum[j]], f[i] - 1ll * (cnt[i * pnum[j]] - cnt[i]) * i);
        ans = max(ans, f[i] + 1ll * cnt[i] * i);
    }
    printf("%lld\n", ans);
    return 0;
}