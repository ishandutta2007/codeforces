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
    int k = floor(sqrt(n));
    vector<int> ans(n, -1);
    int x = n - k;
    for (int i = 0; i < n; i++) {
        ans[x] = i;
        x++;
        if (x >= n || ans[x] != -1) {
            x -= 2 * k;
            x = max(x, 0);
        }
    }

    for (int i : ans) {
        cout << i + 1 << " ";
    }

    return 0;
}//jpscto