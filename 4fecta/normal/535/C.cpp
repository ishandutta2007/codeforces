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

ll a, b, n, l, t, m;

ll getval(ll x) {
    return (x - 1) * b + a;
}

ll sum(ll l, ll r) {
    return (getval(l) + getval(r)) * (r - l + 1) / 2;
}

bool check(ll l, ll r, ll t, ll m) {
    ll mx = getval(r);
    if (mx > t) return 0;
    ll tot = sum(l, r);
    return tot <= t * m;
}

int main() {
    boost();

    cin >> a >> b >> n;
    for (; n > 0; n--) {
        cin >> l >> t >> m;
        ll lo = l, hi = 1e9, mid;
        if (!check(l, l, t, m)) {printf("-1\n"); continue;}
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            mid += (lo + hi) & 1;
            if (check(l, mid, t, m)) lo = mid;
            else hi = mid - 1;
        }
        printf("%lld\n", lo);
    }

    return 0;
}