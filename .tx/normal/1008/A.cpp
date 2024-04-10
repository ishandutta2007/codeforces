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

    string s;
    cin >> s;
    string g = "aouie";
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (g.find(c) != string::npos || c == 'n') {
            continue;
        }
        if (i + 1 == s.size() || g.find(s[i + 1]) == string::npos) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}