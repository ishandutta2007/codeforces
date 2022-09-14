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

    while (tests--) {
       solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 200200;

vector<int> g[MAXN];
int w[MAXN];
int res[MAXN];

int dfs(int v, int d, int p = -1) {
    w[v] = 1;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        w[v] += dfs(u, d + 1, v);
    }
    res[v] = d - (w[v] - 1);
    return w[v];
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);

    sort(res, res + n);
    reverse(res, res + n);

    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += res[i];
    }
    cout << ans << endl;
}