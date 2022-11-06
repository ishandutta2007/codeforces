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

    map<string, int> a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[s]++;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b[s]++;
    }

    int ans = 0;
    auto hop = [&](string s, string t) {
        int x = min(a[s], b[t]);
        a[s] -= x;
        b[t] -= x;
        if (s != t) {
            ans += x;
        }
    };

    vector<string> sz = {"M", "S", "L", "XS", "XXS", "XXXS", "XL", "XXL", "XXXL"};

    for (int i = 0; i < sz.size(); i++) {
        hop(sz[i], sz[i]);
    }

    for (int i = 0; i < sz.size(); i++) {
        hop(sz[i], sz[i]);
        for (int j = 0; j < sz.size(); j++) {
            if (sz[i].length() == sz[j].length()) {
                hop(sz[i], sz[j]);
            }
        }
    }

    cout << ans;

    return 0;
}