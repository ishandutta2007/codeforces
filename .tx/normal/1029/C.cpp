#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

pair<int, int> f(pair<int, int> a, pair<int, int> b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<pair<int, int>> l(n);
    l[0] = a[0];
    for (int i = 1; i < n; i++) {
        l[i] = f(l[i - 1], a[i]);
    }

    vector<pair<int, int>> r(n);
    r[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        r[i] = f(r[i + 1], a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> cur = {-int(1e9), int(2e9)};
        if (i) {
            cur = f(cur, l[i - 1]);
        }
        if (i + 1 < n) {
            cur = f(cur, r[i + 1]);
        }

        if (cur.first < cur.second) {
            ans = max(ans, cur.second - cur.first);
        }
    }

    cout << ans;


    return 0;
}