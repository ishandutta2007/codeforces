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

ll n, ans, sp = 1;

int main() {
    boost();

    cin >> n;
    while (1) {
        ll cnt = (n - 1) / sp + 1;
        if (cnt <= 1) break;
        ll pairs = cnt / 2;
        ans += sp * pairs;
        sp <<= 1;
    }
    printf("%lld\n", ans);

    return 0;
}