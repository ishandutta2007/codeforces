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

int q;
ll u, v, w;
map<ll, ll> cost;

int main() {
    boost();

    cin >> q;
    while (q--) {
        cin >> u;
        if (u == 1) {
            cin >> u >> v >> w;
            while (u != v) {
                if (u > v) {
                    if (!cost.count(u)) cost[u] = 0;
                    cost[u] += w;
                    u >>= 1;
                } else {
                    if (!cost.count(v)) cost[v] = 0;
                    cost[v] += w;
                    v >>= 1;
                }
            }
        } else {
            cin >> u >> v;
            ll ans = 0;
            while (u != v) {
                if (u > v) {
                    if (cost.count(u)) ans += cost[u];
                    u >>= 1;
                } else {
                    if (cost.count(v)) ans += cost[v];
                    v >>= 1;
                }
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}