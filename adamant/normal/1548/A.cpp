#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int add(int a, int b) {
    return (a + b) % mod;
}
int sub(int a, int b) {
    return (a + mod - b) % mod;
}
int mul(int a, int b) {
    return a * b % mod;
}
int bpow(int x, int n) {
    return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
    return bpow(x, mod - 2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> g[n];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    set<int> strong;
    auto recalc = [&](int i) {
        if(g[i].empty() || i > *prev(end(g[i]))) {
            strong.insert(i);
        } else {
            strong.erase(i);
        }
    };
    for(int i = 0; i < n; i++) {
        recalc(i);
    }
    int q;
    cin >> q;
    while(q--) {
        int t, u, v;
        cin >> t;
        if(t == 1) {
            cin >> u >> v;
            u--, v--;
            g[u].insert(v);
            g[v].insert(u);
            recalc(u);
            recalc(v);
        } else if(t == 2) {
            cin >> u >> v;
            u--, v--;
            g[u].erase(v);
            g[v].erase(u);
            recalc(u);
            recalc(v);
        } else {
            cout << strong.size() << "\n";
        }
    }
}

signed main() {
    //ignore = freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}