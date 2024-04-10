// 392699

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

const int N = 5e5;

int n, ans, top, stk[N + 10], a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = 1; i <= n; i++) {
        while (top > 1 && a[stk[top - 1]] >= a[stk[top]] && a[stk[top]] <= a[i]) ans += min(a[stk[top - 1]], a[i]), top--;
        stk[++top] = i;
    }
    n = top;
    for (int i = 1; i <= n; i++) a[i] = a[stk[i]];
    sort(a + 1, a + 1 + n);
    for (int i = max(0ll, n - 2); i; i--) ans += a[i];
    return printf("%lld\n", ans), 0;
}