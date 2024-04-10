#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;
const int MOD = 1000000007;

vector<int> g[N];
int n, m;
int sz[N];
vector<int> cnt_e;

void dfs(int u, int p) {
    sz[u] = 1;
    for (int e : g[u]) {
        if (e == p) continue;
        dfs(e, u);
        sz[u] += sz[e];
    }
    if (u != 1) cnt_e.push_back(sz[u] * (n - sz[u]));
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> m;
    vector<int> p(m);
    for (int &e : p) cin >> e;
    sort(all(p));
    reverse(all(p));
    vector<int> e(n - 1, 1);
    vector<int> cnt(n - 1, 0);
    int t = m / (n - 1);
    int du = m - t * (n - 1);
    for (int i = 0; i < n - 1; i++) cnt[i] = t;
    for (int i = n - 2; i >= n - du - 1; i--) cnt[i]++;
    if (m > n - 1) {
        for (int i = 0; i < n - 1; i++) cnt[i] = 1;
        cnt[n - 2] = m - (n - 2);
    }
    for (int i = 0; i < n - 1; i++) {
        while (cnt[i]) {
            cnt[i]--;
            int tmp = p.back();
            p.pop_back();
            e[i] *= tmp;
            e[i] %= MOD;
        }
    }

    dfs(1, 0);
    sort(all(cnt_e));
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = (ans + cnt_e[i] % MOD * e[i] % MOD) % MOD;
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) g[i].clear();
    cnt_e.clear();
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}