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

const int N = 2e6;

int n, m, a[N + 10], b[N + 10], f[N + 10];
#define cmax(a, b) ((a) < (b) ? (a) = (b) : 0)

void work(int s, int mid) {
    for (int i = s; i <= n; i++) {
        f[i] = f[i - 1];
        if (f[i - 1] >= b[i] - 1) cmax(f[i], b[i] + mid);
        if (f[i - 1] >= b[i] - mid - 1) cmax(f[i], b[i]);
        if (i > 2 && f[i - 2] >= b[i] - mid - 1) cmax(f[i], b[i - 1] + mid);
    }
}

bool chk(int mid) {
    f[1] = 0, work(2, mid);
    if (f[n] >= m - mid - 1) return 1;
    f[2] = max(b[2], mid), work(3, mid);
    return f[n] >= min(m - 1, m + b[2] - mid - 1);
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    // freopen("island.in", "r", stdin), freopen("island.out", "w", stdout);
    fr(m, n);
    for (int i = 1; i <= n; i++) fr(a[i]), a[i + n] = a[i] + m;
    int l = 0, r, ans = 0, p = 1; sort(a + 1, a + 1 + n * 2);
    for (int i = 2; i <= n; i++) if (a[i + 1] - a[i] > a[p + 1] - a[p]) p = i;
    r = a[p + 1] - a[p] - 1;
    for (int i = 1; i <= n; i++) b[i] = a[i + p] - a[p + 1];
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (chk(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return printf("%lld\n", ans), 0;
}