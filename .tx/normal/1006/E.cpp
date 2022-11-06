#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

vector<int> g[222222];
vector<int> a;
int sz[222222];
int f[222222];

void dfs(int v, int p) {
    f[v] = a.size();
    a.push_back(v);
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
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        --x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(0, -1);

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        if (y > sz[x]) {
            cout << "-1\n";
        } else {
            cout << a[f[x] + y - 1] + 1 << "\n";
        }
    }

    return 0;
}