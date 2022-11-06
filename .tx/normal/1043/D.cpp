#ifdef VSE
#define _GLIBCXX_DEBUG
#endif
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
    vector<vector<int>> a;
    vector<vector<int>> p;
    for (int i = 0; i < m; i++) {
        a.emplace_back(n);
        p.emplace_back(n);
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            --x;
            a[i][j] = x;
            p[i][x] = j;
        }
    }

    llong ans = 0;

    int i = 0;
    while (i < n) {
        int j = i + 1;
        int cr = a[0][i];
        while (j < n) {
            int nx = a[0][j];
            bool ok = true;
            for (int k = 0; k < m; k++) {
                if (p[k][nx] != p[k][cr] + j - i) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
            j++;
        }

        llong len = j - i;
        ans += len * (len + 1) / 2;
        i = j;
    }

    cout << ans;


    return 0;
}//nxrnqb