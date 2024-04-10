#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int MAXN = 5e6 + 10;

int n, m, d;

vector<vector<int>> g, gr;

vector<int> usd;

vector<ll> val;

void dfs1(int v, vector<int> &now) {
    usd[v] = 1;
    int a = v / d, b = (v + 1) % d;
    for (auto &to : g[a]) {
        if (!usd[to * d + b]) dfs1(to * d + b, now);
    }
    now.pb(v);
}

void dfs2(int v, vector<int> &now) {
    usd[v] = 1;
    int a = v / d, b = (v - 1 + d) % d;
    now.pb(v);
    for (auto &from : gr[a]) {
        if (!usd[from * d + b]) dfs2(from * d + b, now);
    }
}

int solve() {
    vector<int> ts;
    usd.resize(n * d);
    for (int i = 0; i < n * d; i++) {
        if (!usd[i]) dfs1(i, ts);
    }
    reverse(all(ts));
    vector<int> id(n * d, -1);
    vector<int> dp(n * d);
    usd.assign(n * d, 0);
    vector<int> city(n);
    int cur_id = 0;
    for (auto &v : ts) {
        if (usd[v]) continue;
        vector<int> now;
        dfs2(v, now);
        for (auto &c : now) id[c] = cur_id;
        int cur = 0;
        for (auto &c : now) {
            if (val[c / d] & (1LL << (c % d))) {
                if (city[c / d] == 0) cur++;
                city[c / d] = 1;
            }
        }
        for (auto &c : now) {
            if (val[c / d] & (1LL << (c % d))) {
                city[c / d] = 0;
            }
        }
        if (id[0] == cur_id) {
            dp[cur_id] = cur + 1;
            cur_id++;
            continue;
        }
        int mx = 0;
        for (auto &c : now) {
            for (auto &from : gr[c / d]) {
                int b = (c - 1 + d) % d;
                if (id[from * d + b] != id[c]) {
                    mx = max(mx, dp[id[from * d + b]]);
                }
            }
        }
        if (mx == 0) {
            cur_id++;
            continue;
        }
        dp[cur_id] = cur + mx;
        cur_id++;
    }
    return *max_element(all(dp)) - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> d;
    val.resize(n);
    g.resize(n);
    gr.resize(n);
    int v, u;
    while (m--) {
        cin >> v >> u;
        v--; u--;
        g[v].pb(u);
        gr[u].pb(v);
    }
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < d; j++) {
            if (s[j] == '1') val[i] ^= (1LL << j);
        }
    }
    cout << solve();
    return 0;
}