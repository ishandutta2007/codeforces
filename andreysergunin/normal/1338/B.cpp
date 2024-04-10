#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

    int tests = 1;
    // cin >> tests;

    while (tests--) {
       solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 2e5;

int lower = 0, upper = 0;
vector<int> g[MAXN];
int col[MAXN];

bool dfs(int v, int p = -1, int c = 0) {
    col[v] = c;
    int cnt = 0;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        cnt += dfs(u, v, c ^ 1);
    }
    upper -= max(0, cnt - 1);
    return sz(g[v]) == 1;
}

void solve() {
    int n;
    cin >> n;
    upper = n - 1;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (sz(g[i]) > 1) {
            root = i;
            break;
        }
    }
    assert(root >= 0);
    dfs(root);

    vector<int> leafs;

    for (int v = 0; v < n; ++v) {
        if (sz(g[v]) == 1) {
            leafs.push_back(v);
        }
    }

    lower = 1;
    for (int v : leafs) {
        if (col[v] != col[leafs[0]]) {
            lower = 3;
            break;
        }
    }

    cout << lower << " " << upper << endl;

}