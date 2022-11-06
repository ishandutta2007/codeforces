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

    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[n - 1 - i] && abs(int(s[i]) - s[n - 1 - i]) != 2) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}//rmaati