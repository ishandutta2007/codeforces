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
    if (n > 500) {
        cout << 0;
        return 0;
    }
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; ok && j < n; j++) {
            if (j == i) {
                continue;
            }
            for (int k = 0; ok && k < n; k++) {
                if (k == j || k == i) {
                    continue;
                }
                int sp = 0;
                for (int t = 0; t < 5; t++) {
                    sp += (a[j][t] - a[i][t]) * (a[k][t] - a[i][t]);
                }
                if (sp > 0) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i + 1 << "\n";
    }

    return 0;
}//zqpkcl