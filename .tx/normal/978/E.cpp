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

    int n, w;
    cin >> n >> w;
    int c = 0;
    int mx = 0, mn = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c += x;
        mx = max(mx, c);
        mn = min(mn, c);
    }

    int x = w - mx;
    int y = -mn;

    cout << max(0, x - y + 1);

    return 0;
}