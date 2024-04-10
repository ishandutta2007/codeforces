#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double; 
// using ld = __float128;
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
const int MAXD = 10;

vector<int> g[MAXN];
vector<pii> r[MAXN];

int f[MAXD][MAXD][MAXD][MAXD];
int cur[MAXD];
int cnt = 0;

void bruteForce(int k, int i = 1) {
    if (i > k) {
        ++cnt;
        // for (int i = 1; i <= k; ++i) {
        //     cout << cur[i] << " ";
        // }
        // cout << endl;
        return;
    }

    for (int j = 1; j <= i; ++j) {
        bool ok = !f[i][j][i][j];
        for (int l = 1; l < i; ++l) {
            if (f[i][j][l][cur[l]]) {
                ok = false;
            }
        }

        if (ok) {
            cur[i] = j;
            bruteForce(k, i + 1);
            cur[i] = 0;
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> e(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e[w - 1] = {u, v};
    }

    for (auto [x, y] : e) {
        g[x].push_back(y);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(g[i]); ++j) {
            r[g[i][j]].push_back({sz(g[i]), j + 1});
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(all(r[i]));
        for (int u = 0; u + 1 < sz(r[i]); ++u) {
            int v = u + 1;
            auto [a, b] = r[i][u];
            auto [c, d] = r[i][v];
            f[a][b][c][d] = 1;
        }

        r[i].resize(unique(all(r[i])) - r[i].begin());

        for (int u = 0; u < sz(r[i]); ++u) {
            for (int v = 0; v < sz(r[i]); ++v) {
                if (u == v) {
                    continue;
                }
                auto [a, b] = r[i][u];
                auto [c, d] = r[i][v];
                f[a][b][c][d] = 1;
            }
        }
    }

    bruteForce(k);
    cout << cnt << endl;
}