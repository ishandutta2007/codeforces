#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

vector<int> g[111111];
int d[111111];

void dfs(int v, int p) {
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        d[v] += d[i];
    }
    if (d[v] == 0) {
        d[v] = 1;
    }
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        --x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    dfs(0, -1);

    sort(d, d + n);

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }


    return 0;
}//zorrue