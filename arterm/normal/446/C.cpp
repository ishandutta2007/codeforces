#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

#define M 300300
#define mod 1000000009ll
#define long long long

long ad[4 * M], bd[4 * M], s[4 * M], f[M], sum[M], n, m, a[M];

void pre() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < M; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    sum[0] = 0;
    for (int i = 1; i < M; ++i)
        sum[i] = (sum[i - 1] + f[i]) % mod;
}

long getSum(long a, long b, long len) {
    if (len == 0)
        return a;
    return (sum[len] * b + sum[len - 1] * a) % mod;
}

void nth(long a, long b, long &ax, long &bx, long n) {
    ax = (f[n + 1] * a + f[n] * (b - a)) % mod;
    bx = (f[n + 2] * a + f[n + 1] * (b - a)) % mod;
}

void upd(int v, int l, int r, int le, long a, long b) {
    if (le == r)
        return;
    if (l == le) {
        ad[v] = (ad[v] + a) % mod;
        bd[v] = (bd[v] + b) % mod;
        return;
    }

    s[v] += getSum(a, b, r - le);

    int m = (l + r) / 2;
    if (le < m)
        upd(2 * v, l, m, le, a, b);

    if (m <= le) {
        upd(2 * v + 1, m, r, le, a, b);
    }
    else {
        long ax, bx;
        nth(a, b, ax, bx, m - le);
        upd(2 * v + 1, m, r, m, ax, bx);
    }
}

long get(int v, int l, int r, int le) {
    if (le == r)
        return 0;

    long ax, bx;
    nth(ad[v], bd[v], ax, bx, le - l);
    long ans = getSum(ax, bx, r - le);

    if (l == le)
        return s[v] + ans;
    
    int m = (l + r) / 2;
    if (le < m)
        ans = (ans + get(2 * v, l, m, le)) % mod;
    ans = (ans + get(2 * v + 1, m, r, max(m, le))) % mod;
    return ans;
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        s[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    s[v] = (s[2 * v] + s[2 * v + 1]) % mod;
}

void read() {
    cin >> n >> m;
    ++n;
    for (int i = 1; i < n; ++i)
        cin >> a[i];

    build(1, 1, n);
    int t, l, r;
    for (int i = 0; i < m; ++i) {
        cin >> t >> l >> r;
        ++r;
        if (t == 1) {
            upd(1, 1, n, l, 0, 1);
            upd(1, 1, n, r, -f[r - l], -f[r - l + 1]);
        }
        else {
            long ans = get(1, 1, n, l) - get(1, 1, n, r);
            ans %= mod;
            if (ans < 0)
                ans += mod;
            cout << ans << "\n";
        }
    }
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    pre();
    read();

    return 0;
}