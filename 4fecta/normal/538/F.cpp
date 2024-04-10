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

const int MN = 200005;

int n, a[MN], ans[MN], bit[MN];
vector<pii> q;

void upd(int x, int val) {
    x++;
    for (int i = x; i < MN; i += i & -i) bit[i] += val;
}

int qry(int x) {
    x++;
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q.push_back({a[i], i - 1});
    }
    sort(q.begin(), q.end());
    for (pii p : q) {
        for (int i = 1; i * p.s + 1 < n && i < n; i++) {
            ans[i] += qry(min(i * p.s + i, n)) - qry(i * p.s);
        }
        upd(p.s, 1);
    }
    for (int i = 1; i < n; i++) printf("%d ", ans[i]);

    return 0;
}