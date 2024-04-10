#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txst", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

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

const int P = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

const int MAXN = 404;

vector<int> g[MAXN];
int d[MAXN];
int cnt[MAXN];
int p[MAXN];

void bfs(int n, const vector<int> &st, bool flag = false) {
    for (int i = 0; i < n; ++i) {
        d[i] = n;
        cnt[i] = 0;
    }

    queue<int> q;
    for (int v : st) {
        q.push(v);
        d[v] = 0;
        cnt[v] = 1;
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : g[v]) {
            if (d[u] > d[v] + 1) {
                q.push(u);
                cnt[u] = 1;
                d[u] = d[v] + 1;
                if (flag) {
                    p[u] = v;
                }
            } else if (d[u] == d[v] + 1) {
                ++cnt[u];
            }
        }
    }
}

int dst[MAXN][MAXN];

void solve() {  
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dst[i][j] = (i == j ? 0 : n);
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        dst[u][v] = dst[v][u] = 1;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << dst[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int v = 0; v < n; ++v) {
        bfs(n, {v}, 1);

        for (int u = 0; u < n; ++u) {
            int w = u;
            vector<int> st = {w};
            while (w != v) {
                w = p[w];
                st.push_back(w);
            }
            bfs(n, st);

            // cout << u << " " << v << endl;
            // for (int i = 0; i < n; ++i) {
            //     cout << d[i] << " ";
            // }   
            // cout << endl;


            bool ok = true;
            int cur = 1;

            for (int i = 0; i < n; ++i) {
                if (2 * d[i] + dst[v][u] != dst[v][i] + dst[u][i]) {
                    ok = false;
                    break;
                }
                mul(cur, cnt[i]);
            }
            // cout << ok << " " << cur << endl;
            cout << (ok ? cur : 0) << " ";
        }
        cout << "\n";
    }
}