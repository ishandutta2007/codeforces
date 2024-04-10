#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define int ll
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 800005;

int n, k, a[MN], f[MN], psa[MN], ans = 1LL << 60;

int32_t main() {
    boost();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], f[a[i]]++;
    for (int i = 1; i < MN; i++) psa[i] = f[i] + psa[i - 1];
    for (int i = 1; i <= 200000; i++) {
        int cnt = f[i], ops = 0, lvl = 1;
        while (cnt < k) {
            int lft = i << lvl;
            int rit = lft + (1 << lvl) - 1;
            if (lft > 200000) break;
            int num = psa[rit] - psa[lft - 1];
            if (num >= k - cnt) ops += lvl * (k - cnt), cnt = k;
            else ops += lvl * num, cnt += num;
            lvl++;
        }
        if (cnt >= k) ans = min(ans, ops);
    }
    printf("%lld\n", ans);

    return 0;
}