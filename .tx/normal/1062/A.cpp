#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto sz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 2);
    a[0] = 0;
    a[n + 1] = 1001;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int ca = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1] + 1 && a[i] == a[i + 1] - 1) {
            ca++;
        } else {
            ca = 0;
        }
        ans = max(ans, ca);
    }

    cout << ans;

    return 0;
}//ehxjwj