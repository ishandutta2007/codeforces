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
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            s += x;
        }

        a.push_back({-s, i});
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].second == 0) {
            cout << i + 1;
            return 0;
        }
    }

    return 0;
}