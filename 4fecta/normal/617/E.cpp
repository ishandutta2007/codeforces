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

struct query {
    int i, l, r;
};

const int MN = 100005, SQRT = 316;

int n, m, k, a[MN], ans[MN], cnt, mp[5000005];
query q[MN];

bool cmp(query x, query y) {
    if (x.l / SQRT != y.l / SQRT) return x.l / SQRT < y.l / SQRT;
    return x.r < y.r;
}

int32_t main() {
    boost();

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] ^= a[i - 1];
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }
    mp[0] = 1;
    sort(q + 1, q + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
        while (r < q[i].r) {
            r++;
            cnt += mp[a[r] ^ k];
            mp[a[r]]++;
        }
        while (r > q[i].r) {
            mp[a[r]]--;
            cnt -= mp[a[r] ^ k];
            r--;
        }
        while (l > q[i].l) {
            l--;
            cnt += mp[a[l - 1] ^ k];
            mp[a[l - 1]]++;
        }
        while (l < q[i].l) {
            mp[a[l - 1]]--;
            cnt -= mp[a[l - 1] ^ k];
            l++;
        }
        ans[q[i].i] = cnt;
    }
    for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);

    return 0;
}