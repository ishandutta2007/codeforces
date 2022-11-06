#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto cnt = [&](int x, int y) {
        int res = 0;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] != '*') {
                    continue;
                }
                res++;
            }
        }
        return res;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                continue;
            }
            int c;
            if (a[i][j] == '.') {
                c = 0;
            } else {
                c = a[i][j] - '0';
            }
            if (c != cnt(i, j)) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}