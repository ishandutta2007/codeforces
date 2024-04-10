#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    set<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans.insert(a[0] - d);
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] >= 2 * d) {
            ans.insert(a[i - 1] + d);
            ans.insert(a[i] - d);
        }
    }

    ans.insert(a[n - 1] + d);

    cout << ans.size();

    return 0;
}