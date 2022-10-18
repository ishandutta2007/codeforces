#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;
const int mod = 998244353;

int mul(int a, int b) {
    return (a * b) % mod;
}
int add(int a, int b) {
    return (a + b) % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> g[n];
    set<int> gt[n];
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        gt[y].insert(x);
    }
    set<pair<int, int>> que;
    for(int i = 0; i < n; i++) {
        que.emplace(gt[i].size(), i);
    }
    vector<vector<int>> d(n, vector<int>(n + 1));
    vector<vector<int>> over(n, vector<int>(n + 1));
    auto add = [&](int v, int ln, int c, int o = false) {
        d[v][ln] += c;
        over[v][ln] |= o || (d[v][ln] >= mod);
        d[v][ln] %= mod;
    };
    int ans = 0;
    while(!que.empty()) {
        int v = begin(que)->second;
        que.erase(begin(que));
        add(v, 0, a[v]);
        for(auto u: g[v]) {
            que.erase({gt[u].size(), u});
            gt[u].erase(v);
            que.insert({gt[u].size(), u});
            for(int i = 0; i < n; i++) {
                add(u, i + 1, d[v][i], over[v][i]);
            }
        }
        if(que.empty()) {
            int t = 0, to = 0;
            for(int i = 0; i <= n; i++) {
                if(!to && i > t) {
                    t = i;
                }
                t += d[v][i];
                if(t >= mod || over[v][i]) {
                    to = 1;
                }
                t %= mod;
                if(d[v][i] || over[v][i]) {
                    ans = t;
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}