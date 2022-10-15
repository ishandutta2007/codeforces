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

const int MN = 1000002;

int n, q, u, a[MN], bit[MN];

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
    for (int i = 1; i <= n; i++) cin >> a[i], upd(a[i], 1);
    while (q--) {
        cin >> u;
        if (u < 0) {
            u = -u;
            int lo = 1, hi = n, mid;
            while (lo < hi) {
                mid = (lo + hi + 1) >> 1;
                if (qry(mid - 1) < u) lo = mid;
                else hi = mid - 1;
            }
            upd(lo, -1);
        } else {
            upd(u, 1);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt = qry(i);
        if (cnt > 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");

    return 0;
}