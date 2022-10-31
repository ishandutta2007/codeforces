#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 3e5 + 5, logg = 19;
vector < int > g[maxn];
vector < pair < int, int > > f[maxn];
int dp[maxn][logg], h[maxn], ans;
map < int, int > sum;
map < pair < int, int >, int > goal;
vector < vector < int > > stop[maxn];
int start[maxn];
int add[maxn], pref[maxn], cnt[maxn];

void dfs1(int v, int p) {
    for (auto u : g[v]) {
        if (u != p) dfs1(u, v), pref[v] += pref[u];
    }
    sum.clear();
    goal.clear();
    for (auto u : f[v]) {
        //if (v == 1) cout << u.first << " " << u.second << endl;
        sum[u.first]++;
        if (u.first != u.second) sum[u.second]++;
        goal[u]++;
    }
    int cur = 0;
    for (auto u : f[v]) {
        if (u.first == u.second) {
            cur += (int)f[v].size() - sum[u.first];
            ans += (pref[v] - pref[u.first]);
        }
        else {
            cur += (int)f[v].size() - (sum[u.first] + sum[u.second] - goal[u]);
            ans += (pref[v] - pref[u.first] - pref[u.second]);
        }
    }
    assert(cur % 2 == 0);
    ans += cur / 2;

    //cout << "OK " << f[v].size() << " " << start[v] << endl;

    ans += (int)f[v].size() * start[v];
    ans += cnt[v] * ((int)f[v].size() + start[v] + pref[v]);
    pref[v] += add[v];
    //cout << v << " " << ans << endl;
}

void dfs(int v, int p) {
    dp[v][0] = p;
    h[v] = h[p] + 1;
    for (int i = 1; i < logg; ++i) {
        dp[v][i] = dp[dp[v][i - 1]][i - 1];
    }
    for (auto u : g[v]) {
        if (u != p) dfs(u, v);
    }
}

int get_la(int u, int x) {
    for (int i = 0; i < logg; ++i) {
        if ((x&(1 << i))) u = dp[u][i];
    }
    return u;
}

int get_lca(int u, int v) {
    if (h[u] > h[v]) u = get_la(u, h[u] - h[v]);
    else v = get_la(v, h[v] - h[u]);
    if (u == v) return u;
    for (int i = logg - 1; i >= 0; --i) {
        if (dp[v][i] != dp[u][i]) {
            v = dp[v][i], u = dp[u][i];
        }
    }
    return dp[v][0];
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v, m;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        if (h[u] > h[v]) swap(u, v);
        if (get_lca(u, v) == u) {
            if (u == v) cnt[u]++;
            else {
                f[u].push_back({get_la(v, h[v] - h[u] - 1), get_la(v, h[v] - h[u] - 1)});
                start[v]++;
                add[v]++;
                add[f[u].back().first]--;
            }
        }
        else {
            int to = get_lca(u, v);
            f[to].push_back({get_la(v, h[v] - h[to] - 1), get_la(u, h[u] - h[to] - 1)});
            start[u]++, start[v]++;
            add[u]++, add[v]++, add[f[to].back().first]--;
            add[f[to].back().second]--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (int)f[i].size(); ++j) {
            if (f[i][j].first > f[i][j].second) swap(f[i][j].first, f[i][j].second);
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }
    dfs1(1, 0);
    cout << ans << '\n';
    return 0;
}