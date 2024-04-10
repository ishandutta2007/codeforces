#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
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
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

    int tests = 1;
    cin >> tests;

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

vector<int> g[MAXN];
int c[MAXN];

void solve() {  
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    int res = n;

    for (int w = 0; w < 2; ++w) {
        int cur = 0;
        vector<vector<int>> que(3);
        vector<int> deg(n);

        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            deg[i] = sz(g[i]);
            if (deg[i] == 1) {
                que[c[i]].push_back(i);
            }
        }

        for (int k = 1; cnt < n; k = 3 - k) {
            ++cur;
            while (sz(que[k]) + sz(que[0]) > 0) {
                for (int t : {0, k}) {
                    if (sz(que[t]) > 0) {
                        ++cnt;
                        int v = que[t].back();
                        que[t].pop_back();
                        for (int u : g[v]) {
                            --deg[u];
                            if (deg[u] == 1) {
                                que[c[u]].push_back(u);
                            }
                        }
                    }
                }  
            }
        }

        res = min(res, cur);

        for (int i = 0; i < n; ++i) {
            c[i] = c[i] == 0 ? 0 : 3 - c[i];
        }
    }

    cout << res << endl;
   
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    } 
}