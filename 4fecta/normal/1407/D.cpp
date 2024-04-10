#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

const int MN = 300005;

int n, a[MN], dp[MN];
deque<pii> t1, t2; //both higher all, both lower all

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    t1.push_back({a[1], 0});
    t2.push_back({a[1], 0});
    for (int i = 2; i <= n; i++) {
        for (int j = t1.size() - 1; j >= 0; j--) {
            if (j < t1.size() - 1 && t1[j + 1].f >= a[i]) break;
            dp[i] = min(dp[i], t1[j].s + 1);
        }
        for (int j = t2.size() - 1; j >= 0; j--) {
            if (j < t2.size() - 1 && t2[j + 1].f <= a[i]) break;
            dp[i] = min(dp[i], t2[j].s + 1);
        }
        while (t1.size() && a[i] >= t1.back().f) t1.pop_back();
        while (t2.size() && a[i] <= t2.back().f) t2.pop_back();
        t1.push_back({a[i], dp[i]});
        t2.push_back({a[i], dp[i]});
    }
    printf("%lld\n", dp[n]);

    return 0;
}