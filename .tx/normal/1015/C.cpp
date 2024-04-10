#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    llong s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        s += a[i].first;
    }

    sort(a.begin(), a.end(), [](auto x, auto y) { return x.first - x.second > y.first - y.second; });

    int ans = 0;
    for (int i = 0; i < n && s > m; i++) {
        s -= a[i].first - a[i].second;
        ans++;
    }

    if (s <= m) {
        cout << ans;
    } else {
        cout << -1;
    }

    return 0;
}