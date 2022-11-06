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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        if (a[x] > a[y]) {
            ans[x]--;
        } else if (a[x] < a[y]) {
            ans[y]--;
        }
    }

    vector<int> b(a);
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        ans[i] += lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        cout << ans[i] << " ";
    }

    return 0;
}