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

struct seg {
    int l = 0, r = 0, i = 0;
};

const int MN = 3005;

int n, dp[MN], bit[200005];
seg a[MN];

void upd(int x, int val) {
    for (int i = x; i < 200005; i += i & -i) bit[i] = max(bit[i], val);
}

int qry(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret = max(ret, bit[i]);
    return ret;
}

bool cmp(seg x, seg y) {
    return x.r - x.l < y.r - y.l;
}

bool cmp1(seg x, seg y) {
    return x.l > y.l;
}

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r, a[i].i = i;
        a[n + 1] = {-1, (int) 2e5 + 1, n + 1};
        sort(a + 1, a + n + 2, cmp);
        for (int i = 1; i <= n + 1; i++) {
            vector<seg> v;
            for (int j = 1; j <= n + 1; j++) if (a[i].i != a[j].i && a[i].l <= a[j].l && a[j].r <= a[i].r) v.push_back(a[j]);
            sort(v.begin(), v.end(), cmp1);
            map<int, int> dp1;
            dp1[a[i].r + 1] = 0;
            int best = 0;
            for (seg p : v) {
                auto i1 = dp1.upper_bound(p.r);
                auto i2 = dp1.lower_bound(p.l);
                int tmp = dp[p.i] + i1->s;
                if (tmp > i2->s) dp1[p.l] = tmp, best = tmp;
            }
            dp[a[i].i] = best + 1;
        }
        //for (int i = 1; i <= n; i++) printf("%d ", dp[i]);
        printf("%d\n", dp[n + 1] - 1);
    }

    return 0;
}