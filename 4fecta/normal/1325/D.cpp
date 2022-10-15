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

ll u, v;

int main() {
    boost();

    cin >> u >> v;
    if (u > v || (u % 2) != (v % 2)) return 0 * printf("-1\n");
    assert(u % 2 == v % 2);
    if (!u && !v) return 0 * printf("0\n");
    if (u == v) return 0 * printf("1\n%lld\n", u);
    ll avg = (v - u) / 2;
    if (u & avg) assert(avg > 0), printf("3\n%lld %lld %lld\n", u, avg, avg);
    else assert((u ^ avg) > 0 && avg > 0), printf("2\n%lld %lld\n", u ^ avg, avg);

    return 0;
}