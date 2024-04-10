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

const int MN = 300005;

int n, q, a[MN], l, r, lim[MN], ans[MN], bit[MN], delta = 0;
vector<pii> qs[MN];

void upd(int x, int val) {
    for (int i = x; i < MN; i += i & -i) bit[i] += val;
}

int qry(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

int main() {
    boost();

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= i) lim[i] = i - a[i];
        else lim[i] = 0x3f3f3f3f;
        //if (a[i] <= i) printf("%d ", lim[i]);
        //else printf("-1 ");
    }
    //printf("\n");
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        l = l + 1, r = n - r;
        qs[r].push_back({l, i});
        /*int rem = 0;
        for (int i = l; i <= r; i++) { //how to simulate this loop in log(n) time?
            if (rem >= lim[i]) rem++;
        }
        printf("%d\n", rem);*/
    }
    for (int i = 1; i <= n; i++) {
        if (qry(1) >= lim[i]) {
            int lo = 1, hi = n, mid;
            while (lo < hi) {
                mid = (lo + hi + 1) >> 1;
                if (qry(mid) >= lim[i]) lo = mid;
                else hi = mid - 1;
            }
            lo = min(lo, i);
            upd(1, 1), upd(lo + 1, -1);
        }
        for (pii p : qs[i]) ans[p.s] = qry(p.f);
    }
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);

    return 0;
}