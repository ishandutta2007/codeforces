#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t

const int maxn = 2e5 + 42;
const int inf = 1e9;

int query(char c, int v) {
    cout << c << ' ' << v << endl;
    int u;
    cin >> u;
    return u;
}

void dfs(int v, int p, vector<int> *g, vector<int> &h) {
    for(auto u: g[v]) {
        if(u != p) {
            h[u] = h[v] + 1;
            dfs(u, v, g, h);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> g[n];
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    int k1, k2;
    cin >> k1;
    int x[k1];
    for(int i = 0; i < k1; i++) {
        cin >> x[i];
    }
    cin >> k2;
    int y[k2];
    for(int i = 0; i < k2; i++) {
        cin >> y[i];
    }
    int from = query('B', y[0]);
    vector<int> h(n);
    dfs(from - 1, from - 1, g, h);
    int check = x[0];
    for(int i = 0; i < k1; i++) {
        if(x[i] == from) {
            cout << "C " << x[i] << endl;
            return;
        } else if(h[x[i] - 1] < h[check - 1]) {
            check = x[i];
        }
    }
    int cand = query('A', check);
    for(int i = 0; i < k2; i++) {
        if(cand == y[i]) {
            cout << "C " << check << endl;
            return;
        }
    }
    cout << "C " << -1 << endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}