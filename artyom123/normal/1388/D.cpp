#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

vector<ll> a;
vector<int> b;
vector<vector<int>> gr, g;
vector<ll> dp;

ll ans = 0;
vector<int> p;
vector<int> kek;

void dfs(int v) {
    dp[v] = a[v];
    for (auto &to : gr[v]) {
        dfs(to);
        if (dp[to] >= 0) {
            dp[v] += dp[to];
        }
    }
    ans += dp[v];
    if (dp[v] >= 0) p.pb(v);
    else kek.pb(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    gr.resize(n), g.resize(n);
    for (auto &c : a) cin >> c;
    for (int i = 0; i < n; i++) {
        cin >> b[i]; b[i]--;
        if (b[i] >= 0) {
            g[i].pb(b[i]);
            gr[b[i]].pb(i);
        }
    }
    dp.assign(n, -INFLL);
    for (int i = 0; i < n; i++) {
        if ((int)g[i].size() == 0) {
            dfs(i);
        }
    }
    cout << ans << "\n";
    for (auto &c : p) cout << c + 1 << " ";
    reverse(all(kek));
    for (auto &c : kek) cout << c + 1 << " ";
    return 0;
}