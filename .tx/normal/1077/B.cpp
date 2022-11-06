#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
        if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
            a[i + 1] = 0;
            ans++;
        }
    }

    cout << ans;

    return 0;
}