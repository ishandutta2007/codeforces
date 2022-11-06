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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
    }

    vector<int> used(n);

    function<int(int)> dfs = [&](int v) {
        if (used[v]) {
            return v;
        }
        used[v] = true;
        return dfs(p[v]);
    };

    for (int i = 0; i < n; i++) {
        used.assign(n, false);
        cout << dfs(i) + 1 << " ";
    }

    return 0;
}//eaaibl