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

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------

const int MAXN = 500500;

vector<int> g[MAXN];

void solve() {  
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> col(n);
    vector<vector<int>> c(n);

    for (int i = 0; i < n; ++i) {
        cin >> col[i];
        --col[i];
        c[col[i]].push_back(i);
    }
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        for (int j : c[i]) {
            p.push_back(j);
        }
    }

    vector<int> used(n);
    int timer = 0;

    for (int i : p) {
        ++timer;

        for (int j : g[i]) {
            used[col[j]] = timer;
        }

        int k = 0;
        while (used[k] == timer) {
            ++k;
        }

        if (col[i] != k) {
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] + 1 << " ";
    }
    cout << "\n";
}