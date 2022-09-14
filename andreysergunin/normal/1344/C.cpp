#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------

const int MAXN = 200200;

vector<int> g[2][MAXN];
int used[MAXN];

bool dfs(int v) {
    used[v] = 1;
    for (int u : g[0][v]) {
        if (used[u] == 1) {
            return false;
        } else if (!used[u] && !dfs(u)) {
            return false;
        }
    }
    used[v] = 2;
    return true;
}

void dfs1(int v, int k) {
    used[v] |= (1 << k);
    for (int u : g[k][v]) {
        if (!(used[u] & (1 << k))) {
            dfs1(u, k);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[0][u].push_back(v);
        g[1][v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i] && !dfs(i)) {
            cout << "-1\n";
            return;
        }
    }

    memset(used, 0, sizeof(used));

    int res = 0;
    string s;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++res;
            s += 'A';
        } else {
            s += 'E';
        }
        dfs1(i, 0);
        dfs1(i, 1);
    }

    cout << res << "\n";
    cout << s << "\n";
}