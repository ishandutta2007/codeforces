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

    int n, m;
    cin >> n >> m;
    int t = 0;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t ^= a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        t ^= b[i];
    }

    if (t != 0) {
        cout << "NO";
        return 0;
    }

    vector<vector<int>> ans(n, vector<int>(m));

    for (int i = 0; i + 1 < n; i++) {
        ans[i][m - 1] = a[i];
    }

    t = 0;
    for (int i = 0; i + 1 < m; i++) {
        ans[n - 1][i] = b[i];
        t ^= b[i];
    }

    ans[n - 1][m - 1] = a[n - 1] ^ t;

    cout << "YES\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }



    return 0;
}//mqcgux