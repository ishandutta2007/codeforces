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

    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    bool ok = true;
    for (int i = p; ok && i < n; i++) {
        if (s[i] == '.') {
            if (s[i - p] == '.') {
                s[i] = '1';
                s[i - p] = '0';
            } else {
                int x = s[i - p] - '0';
                s[i] = (1 - x) + '0';
            }
            ok = false;
        } else if (s[i - p] == '.') {
            int x = s[i] - '0';
            s[i - p] = (1 - x) + '0';
            ok = false;
        } else if (s[i] != s[i - p]) {
            ok = false;
        }
    }

    if (ok) {
        cout << "No";
    } else {
        for (char c : s) {
            if (c == '.') {
                cout << '0';
            } else {
                cout << c;
            }
        }
    }

    return 0;
}