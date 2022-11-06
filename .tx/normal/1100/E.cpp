#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

vector<int> g[111111];
int from[111111];
int to[111111];
int w[111111];
int used[111111];

bool dfs(int v, int mw) {
    used[v] = 1;
    for (int id : g[v]) {
        int i = to[id];
        int w = ::w[id];
        if (w <= mw) {
            continue;
        }
        if (used[i] == 1) {
            return true;
        }
        if (used[i] == 0) {
            if (dfs(i, mw)) {
                return true;
            }
        }
    }
    used[v] = 2;
    return false;
}

vector<int> ts;

void fts(int v, int mw) {
    used[v] = 1;
    for (int id : g[v]) {
        int i = to[id];
        int w = ::w[id];
        if (w <= mw) {
            continue;
        }
        if (!used[i]) {
            fts(i, mw);
        }
    }
    ts.push_back(v);
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        from[i] = x;
        to[i] = y;
        w[i] = z;
        g[x].push_back(i);
    }

    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        memset(used, 0, sizeof(used));
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!used[i] && dfs(i, m)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }

    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            fts(i, r);
        }
    }

    reverse(begin(ts), end(ts));

    vector<int> ord(n);
    for (int i = 0; i < n; i++) {
        ord[ts[i]] = i;
    }

    vector<int> ans;

    for (int i = 0; i < m; i++) {
        if (ord[from[i]] > ord[to[i]]) {
            ans.push_back(i);
        }
    }

    cout << r << " " << isz(ans) << "\n";
    for (auto& i : ans) {
        cout << i + 1 << " ";
    }


    return 0;
}//jagxij