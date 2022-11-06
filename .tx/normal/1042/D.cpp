#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    llong t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    llong cs = 0;
    tree<pair<llong, int>> tr;
    tr.insert({0, -1});
    llong ans = 0;
    for (int i = 0; i < n; i++) {
        cs += a[i];
        ans += tr.order_of_key(pair(t - cs, -1));
        tr.insert({-cs, i});
    }

    cout << ans;

    return 0;
}//pejzug