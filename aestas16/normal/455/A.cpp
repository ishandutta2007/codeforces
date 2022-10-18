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
 
const int N = 1e5;
 
int a[N + 10], b[N + 10], f[N + 10];
map<int, int> cnt;
 
struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    int n = fr();
    for (int i = 1; i <= n; i++) {
        fr(a[i]);
        if (a[i] > 0) b[++b[0]] = a[i];
    }
    n = b[0];
    for (int i = 1; i <= n; i++) a[i] = b[i], cnt[a[i]]++;
    sort(a + 1, a + 1 + n), n = unique(a + 1, a + 1 + n) - a - 1, f[1] = cnt[a[1]] * a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] <= a[i] - 2) f[i] = f[i - 1] + cnt[a[i]] * a[i];
        else if (a[i - 1] == a[i] - 1) f[i] = max(f[i - 1], f[i - 2] + cnt[a[i]] * a[i]);
    }
    printf("%lld\n", f[n]);
    return 0;
}