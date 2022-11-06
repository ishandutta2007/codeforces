#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

vector<int> g[333333];
int sz[333333];
int tin[333333];
int tout[333333];
int tmr = 1;

void dfs(int v, int p) {
    tin[v] = tmr++;
    sz[v] = 1;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        sz[v] += sz[i];
    }
    tout[v] = tmr++;
}

bool is_par(int par, int ch) {
    return tin[par] <= tin[ch] && tout[par] >= tout[ch];
}

void solve(istream& cin, ostream& cout) {
    int n, x, y;
    cin >> n >> x >> y;
    --x; --y;
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(x, -1);
    lint ss = 0;
    for (int i : g[x]) {
        if (is_par(i, y)) {
            ss = n - sz[i];
            break;

        }
    }
    ss *= sz[y];
    cout << 1LL * n * (n - 1) - ss;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//wsjbhy