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
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    vector<int> ans;
    ans.push_back(*s.begin());

    for (int i : s) {
        for (int j = 0; j <= 30; j++) {
            int d = 1 << j;
            if (s.count(i + d)) {
                if (ans.size() < 2) {
                    ans.clear();
                    ans.push_back(i);
                    ans.push_back(i + d);
                }
                if (i + 2LL * d <= 1e9 && s.count(i + 2 * d)) {
                    ans.clear();
                    ans.push_back(i);
                    ans.push_back(i + d);
                    ans.push_back(i + 2 * d);
                }
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}