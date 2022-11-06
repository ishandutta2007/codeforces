#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int used[5555];
int ut = 0;
vector<int> g[5555];

int dfs(int v) {
    used[v] = ut;
    int res = 1;
    for (int i : g[v]) {
        if (used[i] != ut) {
            res += dfs(i);
        }
    }
    return res;
}

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    --s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        ut++;
        c[i] = dfs(i);
    }

    ut++;
    dfs(s);

    int ans = 0;
    while (c[s] != n) {
        int mx = -1;
        for (int i = 0; i < n; i++) {
            if (used[i] != ut && (mx == -1 || c[i] > c[mx])) {
                mx = i;
            }
        }
        ans++;
        g[s].push_back(mx);
        ut++;
        c[s] = dfs(s);
    }

    cout << ans << "\n";

    return 0;
}//jknmvb