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

    vector<int> c1(n), c2(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            c1[i]++;
        }
        if (i) {
            c1[i] += c1[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 2) {
            c2[i]++;
        }
        if (i < n - 1) {
            c2[i] += c2[i + 1];
        }
    }

    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        d[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] == 1) {
                d[i][j] = d[i][j - 1] + 1;
            } else {
                d[i][j] = max(d[i][j - 1], c2[i] - (j == n - 1 ? 0 : c2[j + 1]));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int x = (i == 0 ? 0 : c1[i - 1]);
            int y = (j == n - 1 ? 0 : c2[j + 1]);
            int z = d[i][j];
            ans = max(ans, x + y + z);
        }
    }

    cout << ans;

    return 0;
}