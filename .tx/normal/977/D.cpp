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

vector<int> g[111];
lint a[111];
vector<int> ts;
bool used[111];

void dfs(int v) {
    used[v] = true;
    for (int i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
    ts.push_back(v);
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (a[j] * 3 == a[i]) {
                g[i].push_back(j);
            }
            if (a[i] * 2 == a[j]) {
                g[i].push_back(j);
            }
        }
    }

    rep(i, 0, n) {
        if (!used[i]) {
            dfs(i);
        }
    }

    reverse(ts.begin(), ts.end());
    for (int i : ts) {
        cout << a[i] << " ";
    }
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
}//isawld