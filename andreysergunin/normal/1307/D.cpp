// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <iomanip>
// #include <random>

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
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;

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

int n;
vector<int> g[MAXN];

vector<int> bfs(int v) {
    vector<int> dst(n, n);
    dst[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (dst[u] > dst[v] + 1) {
                dst[u] = dst[v] + 1;
                q.push(u);
            }
        }
    }
    return dst;
}

void solve() {
    int m, k;
    cin >> n >> m >> k;
    vector<int> good(n);
    for (int i = 0; i < k; ++i) {
        int u;
        cin >> u;
        --u;
        good[u] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d1 = bfs(0);
    vector<int> d2 = bfs(n - 1);

    vector<pii> p;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            p.push_back({d1[i], d2[i]});
        }
    }

    vector<int> f(n, -n), g(n, -n);

    for (int i = 0; i < k; ++i) {
        int x = p[i].first;
        int y = p[i].second;
        if (f[y] < x) {
            g[y] = f[y];
            f[y] = x;
        } else if (g[y] < x) {            
            g[y] = x;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        vector<int> arr = {f[i], g[i], f[i + 1], g[i + 1]};
        sort(all(arr));
        f[i] = arr[3];
        g[i] = arr[2];
    }

    int lf = 0, rg = d1[n - 1];

    while (rg - lf > 1) {
        int mid = (lf + rg) / 2;
        bool ok = false;
        for (int i = 0; i < k; ++i) {
            int x = p[i].first;
            int y = p[i].second;

            int d = max(0, mid - x);
            if (g[d] + y >= mid) {
                ok = true;
                break;
            }
        }
        if (ok) {
            lf = mid; 
        } else {
            rg = mid;
        }
    }

    cout << lf + 1 << endl;
}