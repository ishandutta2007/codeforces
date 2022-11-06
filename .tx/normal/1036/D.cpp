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
    llong sa = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa += a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);
    llong sb = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        sb += b[i];
    }

    if (sa != sb) {
        cout << -1;
        return 0;
    }

    int i = 0, j = 0;
    sa = 0, sb = 0;

    int ans = 0;

    while (i < n || j < m) {
        ans++;
        sa += a[i++];
        sb += b[j++];
        while (sa != sb) {
            if (sa < sb) {
                sa += a[i++];
            } else {
                sb += b[j++];
            }
        }
    }

    cout << ans;

    return 0;
}//jdsfut