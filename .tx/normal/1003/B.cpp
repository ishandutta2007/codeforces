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

    int a, b, x;
    cin >> a >> b >> x;
    string s = "";

    if (a > b) {
        for (int i = 0; i <= x; i++) {
            s += to_string(i & 1);
            if (i & 1) {
                b--;
            } else {
                a--;
            }
        }
    } else {
        for (int i = 0; i <= x; i++) {
            s += to_string((i + 1) & 1);
            if (i & 1) {
                a--;
            } else {
                b--;
            }
        }
    }

    for (char c : s) {
        cout << c;
        if (c == '0') {
            for (int i = 0; i < a; i++) {
                cout << '0';
            }
            a = 0;
        } else {
            for (int i = 0; i < b; i++) {
                cout << '1';
            }
            b = 0;
        }
    }

    return 0;
}