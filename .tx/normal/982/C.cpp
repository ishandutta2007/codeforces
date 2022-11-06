#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

vector<int> g[111111];
int sz[111111];

void dfs(int v, int p) {
    sz[v] = 1;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        sz[v] += sz[i];
    }
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
    }

    dfs(0, -1);

    if (sz[0] % 2 == 1) {
        cout << -1;
        return 0;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (sz[i] % 2 == 0) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}