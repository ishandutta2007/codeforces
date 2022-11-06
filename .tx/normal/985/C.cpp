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

    int n, k, l;
    cin >> n >> k >> l;
    int m = n * k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int p = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] - a[0] <= l) {
            p = i;
        }
    }

    if (p + 1 < n) {
        cout << 0;
        return 0;
    }

    llong ans = 0;
    int x = 0, y = m - 1;
    while (n) {
        ans += a[x];
        x++;
        --n;
        for (int i = 1; i < k; i++) {
            if (p - x + 1 > n) {
                x++;
            } else {
                y--;
            }
        }
    }

    cout << ans;

    return 0;
}