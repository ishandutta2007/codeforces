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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    llong as = 0;
    llong s1 = 0;
    llong s2 = 0;
    int r = n;
    for (int i = 0; i < n; i++) {
        s1 += a[i];
        while (s2 < s1) {
            --r;
            s2 += a[r];
        }
        if (r <= i) {
            break;
        }
        if (s1 == s2) {
            as = s1;
        }
    }

    cout << as;

    return 0;
}