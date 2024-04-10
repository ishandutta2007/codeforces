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
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> b(n, string(m, '.'));

    for (int i = 1; i + 1 < n; i++) {
        for (int j = 1; j + 1 < m; j++) {
            bool any = false;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    if (a[i + x][j + y] == '.') {
                        any = true;
                        break;
                    }
                }
            }
            if (!any) {
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) {
                            continue;
                        }
                        b[i + x][j + y] = '#';
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}//sralrn