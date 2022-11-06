#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

llong f(llong r) {
    if (r % 2 == 0) {
        return r / 2;
    }

    return (r / 2) - r;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    for (int iq = 0; iq < q; iq++) {
        llong l, r;
        cin >> l >> r;
        cout << f(r) - (l ? f(l - 1) : 0) << "\n";
    }

    return 0;
}//gcqkrp