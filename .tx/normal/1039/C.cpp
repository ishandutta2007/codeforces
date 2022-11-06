#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

const llong M = int(1e9) + 7;

map<llong, vector<int>> g[555555];

int used[555555];
int ut = 1;

int dfs(int v, llong w) {
    used[v] = ut;
    int res = 1;
    auto it = g[v].find(w);
    if (it == g[v].end()) {
        return res;
    }
    for (int i : it->second) {
        if (used[i] != ut) {
            res += dfs(i, w);
        }
    }
    return res;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<llong> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<llong> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2 % M;
    }

    map<llong, set<int>> vs;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        llong w = c[x] ^ c[y];
        g[x][w].push_back(y);
        g[y][w].push_back(x);
        vs[w].insert(x);
        vs[w].insert(y);
    }

    llong bad = 0;
    vector<int> szs;
    for (auto& p: vs) {
        llong w = p.first;
        set<int>& a = p.second;

        szs.clear();
        ut++;
        for (int i : a) {
            if (used[i] != ut) {
                szs.push_back(dfs(i, w));
            }
        }

        int x = 0;
        for (int sz : szs) {
            for (int i = 0; i + 1 < sz; i++) {
                bad = (bad + p2[n - x - 2]) % M;
                x++;
            }
        }
    }

    bad = bad * 2 % M;

    llong all = p2[n] * ((1LL << k) % M) % M;

    llong ans = ((all - bad) % M + M) % M;

    cout << ans;

    return 0;
}//hrsdxr