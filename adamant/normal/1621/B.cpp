#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int inf = 1e9;
const int maxn = 1e5 + 42;

void solve() {
    int n;
    cin >> n;
    int l[n], r[n], c[n];
    pair<int, int> ans;
    map<int, set<int>> left, right;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> c[i];
        left[l[i]].insert(c[i]);
        right[r[i]].insert(c[i]);
        ans = max(ans, {r[i] - l[i] + 1, -c[i]});
        auto lt = begin(left);
        auto rt = prev(end(right));
        ans = max(ans, {
            rt->first - lt->first + 1,
            -(*begin(lt->second) + *begin(rt->second))
        });
        cout << -ans.second << "\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}