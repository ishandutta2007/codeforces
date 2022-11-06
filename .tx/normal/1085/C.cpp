#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n = 3;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(begin(a), end(a));

    set<pair<int, int>> ans;
    for (int i = a[0].first; i <= a[1].first; i++) {
        ans.insert({i, a[0].second});
    }
    for (int i = a[1].first; i <= a[2].first; i++) {
        ans.insert({i, a[2].second});
    }

    for (int i = min(min(a[0].second, a[1].second), a[2].second); i <= max(max(a[0].second, a[1].second), a[2].second); i++) {
        ans.insert({a[1].first, i});
    }

    cout << isz(ans) << "\n";
    for (auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }

    return 0;
}//gfsivn