#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = a[i] - (i == 0 ? 0 : a[i - 1]);
    }

    vector<int> ans;
    for (int k = 1; k <= n; k++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int t = (i == 0 ? 0 : a[i - 1]) + x[i % k];
            if (t != a[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.push_back(k);
        }
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }


    return 0;
}//sjrvvg