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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<bool> del(n);
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < n; i++) {
            if (s[i] == c && k > 0) {
                del[i] = true;
                k--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!del[i]) {
            cout << s[i];
        }
    }

    return 0;
}