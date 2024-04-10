#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 400005, MOD = 998244353;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    else return ret * ret % MOD;
}

int t, n, m, fact[MN], inv[MN], bit[MN], vis[MN];
pii a[MN];

int c(int n, int k) {
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void upd(int x, int val) {
    for (int i = x; i < MN; i += i & -i) bit[i] += val;
}

int qry(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
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
        cin >> n >> m;
        for (int i = 1; i <= m; i++) cin >> a[i].f >> a[i].s;
        int k = 0;
        vector<int> upds;
        for (int i = m; i > 0; i--) {
            int lo = 1, hi = n, mid;
            while (lo < hi) {
                mid = (lo + hi) >> 1;
                if (mid - qry(mid) >= a[i].s) hi = mid;
                else lo = mid + 1;
            }
            if (!vis[lo + 1]) k++;
            vis[lo] = 1;
            upd(lo, 1);
            upds.push_back(lo);
        }
        printf("%lld\n", c(2 * n - 1 - k, n - 1 - k));
        for (int p : upds) {
            vis[p] = 0;
            upd(p, -1);
        }
    }

    return 0;
}