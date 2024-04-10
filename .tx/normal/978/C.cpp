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
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<llong> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    llong s = 0;
    int i = 0;
    for (int im = 0; im < m; im++) {
        llong x;
        cin >> x;
        x -= s + 1;
        while (x >= a[i]) {
            x -= a[i];
            s += a[i];
            i++;
        }
        cout << i + 1 << " " << x + 1 << "\n";
    }

    return 0;
}