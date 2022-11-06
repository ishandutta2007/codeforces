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

const int M = int(1e9) + 7;

lint c[2][222222];
vector<int> g[222222];
lint a[222222];
lint h[222222];
lint sz[222222];
int pp[222222];
int n;

lint ans = 0;

void dfs(int v, int p, int h) {
    pp[v] = p;
    c[h][v] = 1;
    sz[v] = 1;
    ::h[v] = h;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v, 1 - h);
        c[h][v] += c[h][i];
        c[1 - h][v] += c[1 - h][i];
        sz[v] += sz[i];
    }
}

void add(lint v) {
    ans = (ans + v % M + M) % M;
}

void solve(istream& cin, ostream& cout) {
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1, 0);

    rep(v, 0, n) {
        lint h = ::h[v];
        add(a[v] * (c[h][0] - c[h][v] + 1) % M * sz[v]);
        add(-a[v] * (c[1 - h][0] - c[1 - h][v]) * sz[v] % M);
        add(a[v] * (n - sz[v]));
        
        for (int i : g[v]) {
            if (i == pp[v]) {
                continue;
            }
            add(a[v] * c[h][i] % M * (n - sz[i]));
            add(-a[v] * c[1 - h][i] % M * (n - sz[i]));
        }
    }

    cout << ans;
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
}