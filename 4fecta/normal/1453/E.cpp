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

int n, t, d, ok;
vector<int> a[MN];

int dfs(int cur, int par) {
    int mx = -0x3f3f3f3f;
    vector<int> v;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        int tmp = dfs(nxt, cur);
        if (tmp <= 0) ok = 0;
        v.push_back(tmp);
    }
    if (v.empty()) return d;
    sort(v.begin(), v.end(), greater<>());
    int cnt = 0;
    while (v.size() && v.back() < 2) mx = max(mx, v.back() - 1), v.pop_back(), cnt++;
    if (cnt > 1) ok = 0;
    if (cnt == 0) mx = v.front() - 1;
    return mx;
}

bool check(int k) {
    ok = 1;
    d = k;
    dfs(1, 0);
    return ok;
}

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int lo = 1, hi = n, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        printf("%d\n", lo);
        for (int i = 1; i <= n; i++) a[i].clear();
    }

    return 0;
}