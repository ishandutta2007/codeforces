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

    int n;
    llong s;
    cin >> n >> s;
    llong ss = 0;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
        ss += i;
    }

    if (ss < s) {
        cout << -1;
        return 0;
    }

    int l = 0, r = *min_element(begin(a), end(a)) + 1;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        llong x = 0;
        for (int i = 0; i < n; i++) {
            x += max(0, a[i] - m);
        }

        if (x >= s) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l;


    return 0;
}