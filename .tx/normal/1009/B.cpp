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

    string s;
    cin >> s;

    int c1 = 0;
    for (char c : s) {
        if (c == '1') {
            c1++;
        }
    }

    for (char c : s) {
        if (c == '2') {
            while (c1) {
                cout << '1';
                --c1;
            }
        }
        if (c != '1') {
            cout << c;
        }
    }

    while (c1) {
        cout << '1';
        --c1;
    }

    return 0;
}