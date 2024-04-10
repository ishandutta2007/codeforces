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
    vector<int> w(m);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        for (int j = l; j <= r; j++) {
            w[j] = 1;
        }
    }

    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (!w[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i + 1 << " ";
    }

    return 0;
}