#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT =
#define enl "\n";
#define debug(k)                             \
    for (int _ = 0; _ < DEBUG_INDENT; _++) { \
        cout << "  ";                        \
    }                                        \
    cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

vvi cal;
vector<vector<pi>> nei;

// ll get_dist(int i, int j) {
//     if (cal[i][j] != -1) {
//         return cal[i][j];
//     }

//     ll res = min(get_dist(i, i) + 1, get_dist(j, j) + 1);
//     for (pi ne : nei[j]) {
//         res = min(res, 1 + i, ne.f);
//     }
//     for (pi ne : nei[i]) {
//     }

//     return cal[i][j] = res;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        cal.clear();
        cal.resize(n + 1, vi(n + 1, -1));
        cal[1][n] = cal[n][1] = 0;
        nei.clear();
        nei.resize(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            nei[a].push_back({b, w});
            nei[b].push_back({a, w});
        }
        queue<pi> bfs;
        bfs.push({1, n});
        bfs.push({n, 1});
        while (bfs.size()) {
            pi cur = bfs.front();
            bfs.pop();
            int curd = cal[cur.f][cur.s];
            if (cur.f == cur.s) {
                for (int i = 1; i <= n; i++) {
                    if (cal[i][cur.f] == -1) {
                        cal[i][cur.f] = cal[cur.f][i] = 1 + curd;
                        bfs.push({i, cur.f});
                        bfs.push({cur.f, i});
                    }
                }
            }
            for (pi ne : nei[cur.f]) {
                if (cal[ne.f][cur.s] == -1) {
                    cal[ne.f][cur.s] = 1 + curd;
                    bfs.push({ne.f, cur.s});
                }
            }
            for (pi ne : nei[cur.s]) {
                if (cal[cur.f][ne.f] == -1) {
                    cal[cur.f][ne.f] = 1 + curd;
                    bfs.push({cur.f, ne.f});
                }
            }
        }

        // vector<int> dist1(n);
        // {
        //     dist1[1] = 1;
        //     queue<int> bfs;
        //     bfs.push(1);
        //     while (bfs.size()) {
        //         int cur = bfs.front();
        //         bfs.pop();
        //         for (pi ne : nei[cur]) {
        //             if (!dist1[ne.f]) {
        //                 dist1[ne.f] = dist1[cur] + 1;
        //                 bfs.push(ne.f);
        //             }
        //         }
        //     }
        // }
        // vector<int> distn(n);
        // {
        //     distn[n] = n;
        //     queue<int> bfs;
        //     bfs.push(1);
        //     while (bfs.size()) {
        //         int cur = bfs.front();
        //         bfs.pop();
        //         for (pi ne : nei[cur]) {
        //             if (!distn[ne.f]) {
        //                 distn[ne.f] = distn[cur] + 1;
        //                 bfs.push(ne.f);
        //             }
        //         }
        //     }
        // }
        ll res = 6e18;
        for (int i = 1; i <= n; i++) {
            for (pi ne : nei[i]) {
                // cout << i << " " << ne.f << " | " << cal[i][ne.f] << " / "
                //      << ne.s << endl;
                res = min(res, (ll)(cal[i][ne.f] + 1) * (ll)(ne.s));
            }
        }
        cout << res << "\n";
    }
    return 0;
}