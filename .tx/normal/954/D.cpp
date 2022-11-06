#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

vector<int> g[1111];
int was[1111][1111];

vector<int> dist(int n, int s) {
    vector<int> d(n, 1e9);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i : g[v]) {
            if (d[i] > d[v] + 1) {
                d[i] = d[v] + 1;
                q.push(i);
            }
        }
    }

    return d;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s; --t;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        was[x][y] = was[y][x] = 1;
    }

    vector<int> ds = dist(n, s);
    vector<int> dt = dist(n, t);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (was[i][j]) {
                continue;
            }
            int nd = min(ds[i] + dt[j] + 1, ds[j] + dt[i] + 1);
            if (nd >= ds[t]) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}//wysgha