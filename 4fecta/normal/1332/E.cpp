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

const ll MOD = 998244353;

ll fpow(ll b, ll p) {
    if (!p) return 1;
    ll ret = fpow(b, p / 2);
    if (p % 2) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

ll n, m, l, r;

int32_t main() {
    boost();

    cin >> n >> m >> l >> r;
    ll cnt = n * m;
    ll zerocnt = (r - l + 1) / 2;
    ll onecnt = (r - l + 1) / 2;
    if (r % 2 == l % 2) {
        if (r % 2) onecnt++;
        else zerocnt++;
    }
    //printf("%lld %lld\n", onecnt, zerocnt);
    if (cnt % 2) {
        cout << fpow(onecnt + zerocnt, cnt) % MOD;
    } else {
        ll tot = fpow(onecnt + zerocnt, cnt);
        ll odd = fpow(onecnt - zerocnt, cnt);
        ll diff = (tot - odd) * fpow(2, MOD - 2);
        ll ans = tot - diff;
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
        printf("%lld\n", ans % MOD);
    }


    return 0;
}