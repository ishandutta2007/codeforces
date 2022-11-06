#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

template<typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    const int X = 111111;
    vector<int> l(X, -1), r(X, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (l[a[i]] == -1) {
            l[a[i]] = i;
        }
        r[a[i]] = i;
    }

    vector<int> ls, rs;
    for (int i = 0; i < X; i++) {
        if (l[i] != -1) {
            ls.push_back(l[i]);
        }
        if (r[i] != -1) {
            rs.push_back(r[i]);
        }
    }

    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end());

    llong ans = 0;
    for (int i : ls) {
        auto it = upper_bound(rs.begin(), rs.end(), i);
        ans += rs.end() - it;
    }

    cout << ans;

    return 0;
}