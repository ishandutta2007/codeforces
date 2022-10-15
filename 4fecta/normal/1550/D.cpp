#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005, MOD = 1e9 + 7;

int t, n, l, r, a[MN], ans, cnt, fact[MN], inv[MN];

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int score() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i + j == a[i] + a[j]) ret++;
        }
    }
    return ret;
}

void rec(int id) {
    if (id == n + 1) {ans = max(ans, score()); return;}
    for (int i = l; i <= r; i++) {
        if (i == id) continue;
        a[id] = i;
        rec(id + 1);
    }
}

void pr(int id) {
    if (id == n + 1) {
        if (score() == ans) {
            cnt++;
            for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
            printf("\n");
        }
        return;
    }
    for (int i = l; i <= r; i++) {
        if (i == id) continue;
        a[id] = i;
        pr(id + 1);
    }
}

int c(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int get(int n, int a, int b) {
    if (a < 0 || b < 0) return 0;
    int x = n - a, y = n - b;
    return c(n - x - y, n / 2 - x);
}

int32_t main() {
    boost();

    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        int cap = min(1 - l, r - n);
        int ans = cap * get(n, n, n) % MOD;
        if (n % 2) ans = (ans + cap * get(n, n, n)) % MOD;
        for (int i = cap + 1; i <= cap + n + n; i++) {
            int a = min(n, r - i), b = min(n - l - i + 1, n);
            ans = (ans + get(n, a, b)) % MOD;
            if (n % 2) ans = (ans + get(n, b, a)) % MOD;
        }
        printf("%lld\n", ans);
    }

    return 0;
}