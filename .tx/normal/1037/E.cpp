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

    int n, m, k;
    cin >> n >> m >> k;
    vector<set<int>> g(n);
    vector<int> d(n);
    vector<pair<int, int>> es(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        es[i] = {x, y};
        d[x]++;
        d[y]++;
        g[x].insert(y);
        g[y].insert(x);
    }

    reverse(es.begin(), es.end());
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        s.insert({d[i], i});
    }

    vector<int> ans(m);

    for (int im = 0; im < m; im++) {
        while (!s.empty() && s.begin()->first < k) {
            auto v = *s.begin();
            s.erase(s.begin());
            for (int i : g[v.second]) {
                if (s.count({d[i], i})) {
                    s.erase({d[i], i});
                    d[i]--;
                    s.insert({d[i], i});
                }
            }
        }

        ans[im] = s.size();
        int x = es[im].first;
        int y = es[im].second;
        if (s.count({d[x], x}) && s.count({d[y], y})) {
            s.erase({d[x], x});
            d[x]--;
            s.insert({d[x], x});
            s.erase({d[y], y});
            d[y]--;
            s.insert({d[y], y});
            g[x].erase(y);
            g[y].erase(x);
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i : ans) {
        cout << i << "\n";
    }

    return 0;
}//xrnatg