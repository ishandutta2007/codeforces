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

int n, k, ans, L = 1, R, a[N + 10], cnt[N + 10], f[2][N + 10];

void add(int x) { ans += cnt[x], cnt[x]++; }
void del(int x) { cnt[x]--, ans -= cnt[x]; }
int val(int l, int r) {
    while (L > l) add(a[--L]);
    while (L < l) del(a[L++]);
    while (R > r) del(a[R--]);
    while (R < r) add(a[++R]);
    return ans;
}

void solve(int l, int r, int ql, int qr, int tot) {
    if (l > r) return;
    int mid = (l + r) >> 1, qmid = ql;
    for (int i = ql; i <= min(qr, mid); i++) {
        int tmp = f[(tot & 1) ^ 1][i - 1] + val(i, mid);
        if (tmp < f[tot & 1][mid]) f[tot & 1][mid] = tmp, qmid = i;
    }
    solve(l, mid - 1, ql, qmid, tot), solve(mid + 1, r, qmid, qr, tot);
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, k);
    for (int i = 1; i <= n; i++) fr(a[i]);
    memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
    for (int i = 1; i <= k; i++) solve(1, n, 1, n, i & 1);
    printf("%lld\n", f[k & 1][n]);
    return 0;
}