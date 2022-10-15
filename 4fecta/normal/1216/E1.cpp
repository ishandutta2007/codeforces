#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

ll sum(ll l, ll r) {
    return (l + r) * (r - l + 1) / 2;
}

ll calc(ll x) {
    ll k = 1;
    ll ans = 0;
    for (int i = 1; k <= x; i++, k *= 10) ans += i * sum(x - min(x, 10 * k - 1) + 1, x - k + 1);
    return ans;
}

ll calc1(ll x) {
    ll k = 1;
    ll ans = 0;
    for (int i = 1; k <= x; i++, k *= 10) ans += i * (min(x, 10 * k - 1) - k + 1);
    return ans;
}

void solve() {
    ll k;
    cin >> k;
    k--;
    ll x = 0;
    for (ll i = 1 << 29; i > 0; i >>= 1) if (calc(x + i) <= k) x += i;
    k -= calc(x);
    x = 0;
    for (ll i = 1 << 29; i > 0; i >>= 1) if (calc1(x + i) <= k) x += i;
    k -= calc1(x);
    cout << to_string(x + 1)[k] << '\n';
}

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}