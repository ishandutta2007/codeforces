#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int d[111][111111];
vector<int> g[111111];

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> a(n);
    vector<vector<int>> bt(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        bt[a[i]].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int ik = 0; ik < k; ik++) {
        for (int i = 0; i < n; i++) {
            d[ik][i] = 1e9;
        }
        queue<int> q;
        for (int i : bt[ik]) {
            d[ik][i] = 0;
            q.push(i);
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int i : g[v]) {
                if (d[ik][i] > d[ik][v] + 1) {
                    d[ik][i] = d[ik][v] + 1;
                    q.push(i);
                }
            }
        }
    }

    vector<int> ts(k);

    for (int i = 0; i < n; i++) {
        for (int ik = 0; ik < k; ik++) {
            ts[ik] = d[ik][i];
        }

        nth_element(ts.begin(), ts.begin() + s, ts.end());

        int ans = 0;
        for (int is = 0; is < s; is++) {
            ans += ts[is];
        }
        cout << ans << " ";
    }

    return 0;
}