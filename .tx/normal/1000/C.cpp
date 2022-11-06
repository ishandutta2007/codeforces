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
    map<llong, int> d;
    for (int i = 0; i < n; i++) {
        llong x, y;
        cin >> x >> y;
        d[x]++;
        d[y + 1]--;
    }

    vector<llong> ans(n + 1, 0);
    vector<llong> l(n + 1, -1);
    int c = 0;
    for (auto& p : d) {
        if (p.second == 0) {
            continue;
        }
        llong x = p.first;
        if (l[c] != -1) {
            ans[c] += x - l[c];
            l[c] = -1;
        }
        c += p.second;
        l[c] = x;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}