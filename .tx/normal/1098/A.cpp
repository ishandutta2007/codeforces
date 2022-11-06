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
int s[111111];
int a[111111];

void dfs(int v, int p, int h) {
    if (h & 1) {
        int mn = int(1e9) + 1;
        for (int i : g[v]) {
            mn = min(mn, s[i]);
        }
        if (mn == int(1e9) + 1) {
            s[v] = s[p];
        } else {
            s[v] = mn;
        }
    }

    a[v] = s[v] - (p == -1 ? 0 : s[p]);

    for (int i : g[v]) {
        dfs(i, v, h + 1);
    }
}

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
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
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    dfs(0, -1, 0);

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            cout << -1;
            return 0;
        }
    }

    llong ans = accumulate(a, a + n, 0LL);

    cout << ans << "\n";

    return 0;
}//lfrsxa