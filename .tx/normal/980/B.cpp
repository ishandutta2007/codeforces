#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<char>> a(4, vector<char>(n, '.'));
    if (k % 2 == 0) {
        for (int i = 0; i < k / 2; i++) {
            a[1][i + 1] = a[2][i + 1] = '#';
        }
    } else {
        int i = n / 2;
        a[1][i] = '#';
        --i;
        k--;
        while (k > 0 && i >= 1) {
            a[1][i] = a[1][n - i - 1] = '#';
            k -= 2;
            i--;
        }
        while (k > 0) {
            i++;
            a[2][i] = a[2][n - i - 1] = '#';
            k -= 2;
        }
    }

    cout << "YES\n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}