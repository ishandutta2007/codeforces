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

    vector<int> d(8, 1e9);
    d[0] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;
        int m = 0;
        for (char c : s) {
            m |= 1 << (c - 'A');
        }
        d[m] = min(d[m], x);
    }

    int ans = 1e9;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if ((i | j | k) == 7 && d[i] < 1e9 && d[j] < 1e9 && d[k] < 1e9) {
                    ans = min(ans, d[i] + d[j] + d[k]);
                }
            }
        }
    }

    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}//cfxqzz