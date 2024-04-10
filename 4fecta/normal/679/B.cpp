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

pii best;
int m;

int cb(int x) {
    return x * x * x;
}

void rec(int m, int steps, int subtracted) {
    if (m == 0) {
        best = max(best, make_pair(steps, subtracted));
        return;
    }
    int x = 1;
    while (cb(x + 1) <= m) ++x;
    rec(m - cb(x), steps + 1, subtracted + cb(x));
    if (x > 0) rec(cb(x) - 1 - cb(x - 1), steps + 1, subtracted + cb(x - 1));
}

int32_t main() {
    boost();

    cin >> m;
    rec(m, 0, 0);
    printf("%lld %lld\n", best.f, best.s);

    return 0;
}