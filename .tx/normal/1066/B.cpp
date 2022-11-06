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

    int n, r;
    cin >> n >> r;
    --r;
    vector<int> a;
    a.push_back(-r - 1);
    for (int i = 0; i <= n; i++) {
        if (i < n) {
            int x;
            cin >> x;
            if (x == 0) {
                continue;
            }
        } else {
            i = n + r;
        }
        if (i - a.back() - 1 > 2 * r) {
            cout << -1;
            return 0;
        }
        if (a.size() < 2) {
            a.push_back(i);
            continue;
        }
        int l = a[a.size() - 2];
        if (i - l - 1 <= 2 * r) {
            a.pop_back();
        }
        a.push_back(i);
    }

    if (a.empty() || a.back() + r < n - 1) {
        cout << -1;
        return 0;
    }

    cout << a.size() - 2;

    return 0;
}//pkroqc