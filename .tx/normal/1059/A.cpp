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

    int n, l, a;
    cin >> n >> l >> a;
    int ans = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ans += (x - c) / a;
        c = x + y;
    }
    ans += (l - c) / a;

    cout << ans;

    return 0;
}//btighf