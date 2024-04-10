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

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int count(int lim, int a, int b) {
    int ret = min(lim, b - 1);
    int lcm = a * b / gcd(a, b);
    if (lim < lcm) return ret;
    int cnt = lim / lcm;
    int mx = cnt * lcm;
    //printf("mx: %d\n", mx);
    if (lim - mx < b) ret -= b - (lim - mx + 1);
    ret += cnt * b;
    return ret;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int a, b, q, l, r;
        cin >> a >> b >> q;
        if (a > b) swap(a, b);
        while (q--) {
            cin >> l >> r;
            int rng = r - l + 1;
            printf("%lld ", rng - count(r, a, b) + count(l - 1, a, b));
        }
        printf("\n");
    }

    return 0;
}