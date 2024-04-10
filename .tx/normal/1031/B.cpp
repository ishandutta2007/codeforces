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
    --n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++) {
        cin >> b[j];
    }

    vector<int> t(n + 1);
    for (t[n] = 0; t[n] <= 3; t[n]++) {
        bool ok = true;
        for (int i = n - 1; i >= 0; i--) {
            bool any = false;
            for (t[i] = 0; t[i] <= 3; t[i]++) {
                if (a[i] == (t[i] | t[i + 1]) && b[i] == (t[i] & t[i + 1])) {
                    any = true;
                    break;
                }
            }
            if (!any) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            for (int i : t) {
                cout << i << " ";
            }
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}//upcthl