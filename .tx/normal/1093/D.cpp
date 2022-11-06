#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

const int M = 998244353;

vector<int> g[333333];
int c[333333];

pair<int, int> dfs(int v, int cc) {
    c[v] = cc;
    pair<int, int> res = {1, 0};
    for (int i : g[v]) {
        if (!c[i]) {
            auto t = dfs(i, 3 - cc);
            if (t.first == -1) {
                return {-1, -1};
            }
            res.first += t.second;
            res.second += t.first;
        } else if (c[i] == cc) {
            return {-1, -1};
        }
    }

    return res;
}

int p2[333333];

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    p2[0] = 1;
    for (int i = 1; i < 333333; i++) {
        p2[i] = p2[i - 1] * 2 % M;
    }

    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int n, m;
        cin >> n >> m;
        fill_n(g, n, vector<int>());
        fill_n(c, n, 0);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int ans = 1;

        for (int i = 0; i < n; i++) {
            if (!c[i]) {
                auto t = dfs(i, 1);
                if (t.first == -1) {
                    ans = 0;
                    break;
                }
                ans = 1LL * ans * (p2[t.first] + p2[t.second]) % M;
            }
        }

        cout << ans << "\n";
    }


    return 0;
}//ocbjky