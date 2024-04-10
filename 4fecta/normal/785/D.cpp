#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005, MOD = 1e9 + 7;

int n, a[MN], pre[MN], suf[MN], dp[MN], fact[MN], inv[MN], ans = 0;
string s;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int ch(int n, int k) {
    return fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}

int calc(int f, int s) {
    return ch(f + s, f);
}

int32_t main() {
    boost();

    cin >> s;
    n = s.size();
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == ')') a[i] = 1;
        fact[i] = i * fact[i - 1] % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i]) pre[i]++;
        pre[i] += pre[i - 1];
    }
    for (int i = n; i > 0; i--) {
        if (a[i]) suf[i]++;
        suf[i] += suf[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]) continue;
        int f = pre[i], s = suf[i];
        ans += ch(f + s - 1, f); ans %= MOD;
    }
    printf("%lld\n", ans);

    return 0;
}