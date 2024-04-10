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

    int k;
    cin >> k;
    map<int, pair<int, int>> m;
    for (int ik = 0; ik < k; ik++) {
        int s = 0;
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        for (int i = 0; i < n; i++) {
            int cs = s - a[i];
            if (m.find(cs) != m.end()) {
                cout << "YES\n";
                cout << ik + 1 << " " << i + 1 << "\n";
                cout << m[cs].first + 1 << " " << m[cs].second + 1 << "\n";
                return 0;
            }
        }
        for (int i = 0; i < n; i++) {
            m[s - a[i]] = {ik, i};
        }
    }

    cout << "NO";

    return 0;
}