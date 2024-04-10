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

const int MN = 1000005;

int n, a[MN], pre[MN], q, l, r, bit[MN], ans[MN];
map<int, int> lst;
vector<pii> Q[MN];

void upd(int x, int val) {
    for (int i = x; i < MN; i += i & -i) bit[i] ^= val;
}

int qry(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret ^= bit[i];
    return ret;
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = a[i] ^ pre[i - 1];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        Q[r].push_back({l, i});
    }
    for (int i = 1; i <= n; i++) {
        if (lst.count(a[i])) upd(lst[a[i]], a[i]);
        upd(i, a[i]);
        lst[a[i]] = i;
        for (pii p : Q[i]) {
            int dist = qry(i) ^ qry(p.f - 1);
            ans[p.s] = dist ^ pre[i] ^ pre[p.f - 1];
        }
    }
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);

    return 0;
}