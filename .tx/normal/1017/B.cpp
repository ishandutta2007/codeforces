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
    string a, b;
    cin >> n >> a >> b;
    int c0 = 0, c1 = 0;
    int cb0 = 0;
    for (char c : a) {
        if (c == '0') {
            c0++;
        } else {
            c1++;
        }
    }

    llong ans = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] == '0') {
            if (a[i] == '0') {
                ans += c1;
                c0--;
            } else {
                ans += c0;
                c1--;
            }
            cb0++;
        }
    }

    cout << ans;

    return 0;
}//awubiw