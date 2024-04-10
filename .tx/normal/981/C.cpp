#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

vector<int> g[111111];
pair<int, int> ds[111111];

int dfs(int v, int p) {
    for (int i : g[v]) {
        if (i != p) {
            return dfs(i, v);
        }
    }
    return v;
}

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        ds[x].first++;
        ds[y].first++;
    }
    for (int i = 0; i < n; i++) {
        ds[i].second = i;
    }

    sort(ds, ds + n);
    if (ds[n - 2].first > 2) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n" << ds[n - 1].first << "\n";

    int x = ds[n - 1].second;
    for (int i : g[x]) {
        cout << x + 1 << " " << dfs(i, x) + 1 << "\n";
    }


    return 0;
}