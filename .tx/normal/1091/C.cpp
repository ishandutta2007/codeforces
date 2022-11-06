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
    cin >> n;
    set<llong> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i) {
            continue;
        }
        llong x = 1LL * (n - i + 2) * (n / i) / 2;
        ans.insert(x);
        llong y = 1LL * (n - n / i + 2) * i / 2;
        ans.insert(y);
    }

    for (auto& i : ans) {
        cout << i << " ";
    }

    return 0;
}//lxcfwi