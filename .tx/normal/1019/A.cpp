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
    if (m == 1) {
        cout << 0;
        return 0;
    }
    vector<vector<pair<int, int>>> a(m);
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        a[x].emplace_back(y, i);
        if (x != 0) {
            p.emplace_back(y, i);
        }
    }

    for (auto& t : a) {
        sort(t.begin(), t.end());
    }
    sort(p.begin(), p.end());

    llong ans = 1e18;
    vector<int> used(n);
    for (int t = 1; t <= n; t++) {
        llong c = 0;
        int v = a[0].size();
        for (int i = 1; i < m; i++) {
            if (a[i].size() >= t) {
                int x = a[i].size() - t + 1;
                for (int j = 0; j < x; j++) {
                    c += a[i][j].first;
                    used[a[i][j].second] = 1;
                    v++;
                }
            }
        }
        for (int i = 0; v < t; i++) {
            if (!used[p[i].second]) {
                v++;
                c += p[i].first;
            }
        }
        fill(used.begin(), used.end(), 0);
        ans = min(ans, c);
    }

    cout << ans;

    return 0;
}//dszgvn