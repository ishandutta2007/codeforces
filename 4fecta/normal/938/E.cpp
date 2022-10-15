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

const int MN = 1000005, MOD = 1e9 + 7;

int n, a[MN], ans, fact[MN], inv[MN];

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int calc(int x) {
    //if (n - x - 1 < 0 || n - x + 1 < 0) return 0;
    return fact[n - x - 1] * inv[n - x + 1] % MOD;
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    fact[0] = inv[n + 1] = 1;
    int cur = 0, cnt = 0;
    for (int i = 1; i <= n + 1; i++) fact[i] = fact[i - 1] * i % MOD;
    for (int i = n; i >= 1; i--) inv[i] = inv[i + 1] * i % MOD;
    for (int i = 1; i <= n && a[i] != a[n]; i++) {
        if (a[i] == a[i - 1]) cnt++;
        else cur += cnt, cnt = 1;
        //printf("%lld\n", calc(cur));
        ans = (ans + calc(cur) * a[i] % MOD) % MOD;
        //printf("%lld\n", ans);
    }
    printf("%lld\n", ans % MOD);

    return 0;
}