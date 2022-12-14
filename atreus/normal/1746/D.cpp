#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;

vector<int> t[MAXN];
int s[MAXN];
ll dp[MAXN], ext[MAXN];

void dfs(int v, int k) {
    int sz = t[v].size();
    if (sz == 0) {
        dp[v] = 1LL * k * s[v];
        ext[v] = s[v];
        return;
    }
    vector<ll> e;
    dp[v] = 1LL * k * s[v];
    for (auto u : t[v]) {
        dfs(u, k / sz);
        dp[v] += dp[u];
        e.push_back(ext[u]);
    }
    sort(e.begin(), e.end(), greater<ll>());
    for (int i = 0; i < k % sz; i++)
        dp[v] += e[i];
    ext[v] = e[k % sz] + s[v];
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        t[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    dfs(1, k);
    cout << dp[1] << '\n';
    for (int i = 1; i <= n; i++) {
        t[i].clear();
        dp[i] = ext[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}