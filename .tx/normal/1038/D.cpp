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
    vector<int> a(n);
    llong s = 0;
    int cp = 0, cn = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += abs(a[i]);
        if (a[i] >= 0) {
            cp++;
        } else {
            cn++;
        }
    }

    if (n == 1) {
        cout << a[0];
        return 0;
    }

    if (cp == n) {
        cout << s - 2 * *min_element(a.begin(), a.end());
    } else if (cn == n) {
        cout << s + 2 * *max_element(a.begin(), a.end());
    } else {
        cout << s;
    }


    return 0;
}//iicvuz