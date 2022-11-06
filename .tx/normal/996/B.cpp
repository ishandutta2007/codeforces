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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x = *min_element(a.begin(), a.end());
    x -= x % n;
    for (int i = 0; i < n; i++) {
        a[i] -= x;
    }

    int i = 0;
    int t = 0;
    while (true) {
        if (a[i] - t <= 0) {
            cout << i + 1;
            break;
        }
        t++;
        i = (i + 1) % n;
    }

    return 0;
}