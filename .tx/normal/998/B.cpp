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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k1 = 0, k2 = 0;
    vector<int> b;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] & 1) {
            k1++;
        } else {
            k2++;
        }
        if (k1 == k2) {
            b.push_back(abs(a[i] - a[i + 1]));
        }
    }

    sort(b.begin(), b.end());

    int ans = 0;
    for (int i : b) {
        if (i <= k) {
            ans++;
            k -= i;
        }
    }

    cout << ans;

    return 0;
}