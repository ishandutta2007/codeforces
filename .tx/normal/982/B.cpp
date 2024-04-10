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

    int n;
    cin >> n;
    set<pair<int, int>> e, f;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        e.insert({x, i + 1});
    }

    string s;
    cin >> s;

    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '0') {
            cout << e.begin()->second;
            f.insert(*e.begin());
            e.erase(e.begin());
        } else {
            cout << f.rbegin()->second;
            f.erase(*f.rbegin());
        }
        cout << " ";
    }

    return 0;
}