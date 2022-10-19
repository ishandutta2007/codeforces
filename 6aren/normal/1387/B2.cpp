#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

int sz[N], n;
vector<int> g[N];

void dfs(int u, int p = 0) { 
    sz[u] = 1;
    for (int e : g[u]) {
        if (e != p) {
            dfs(e, u);
            sz[u] += sz[e];
        }
    }
}

int get_centroid(int u, int tree_size, int p = 0) {
    for (int e : g[u]) {
        if (e != p && sz[e] * 2 > tree_size) {
            return get_centroid(e, tree_size, u);
        }
    }

    return u;
}

int dep[N];
vector<int> vec[N];

void dfs2(int u, int p, int id) {
    vec[id].pb(u);
    dep[u] = dep[p] + 1;
    for (int e : g[u]) {
        if (e == p) continue;
        dfs2(e, u, id);
    }
}

vector<int> shift(vector<int> a, int l) {
    vector<int> ans(a.begin() + l, a.end());
    for (int i = 0; i < l; i++) ans.pb(a[i]);
    return ans;
}

int res[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    int centroid = get_centroid(1, n);
    int id = 0;
    for (int e : g[centroid]) {
        dfs2(e, centroid, id);
        id++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += 2 * dep[i];
    cout << ans << endl;
    int mx = 0;
    int mn_id = 0;
    vector<int> good;
    for (int i = 0; i < id; i++) {
        mx = max(mx, (int) vec[i].size());
        if (vec[i].size() < vec[mn_id].size()) mn_id = i;
    }
    vec[mn_id].pb(centroid);
    for (int i = 0; i < id; i++) for (int e : vec[i]) good.pb(e);
    vector<int> good2 = shift(good, mx);
    for (int i = 0; i < n; i++) {
        res[good[i]] = good2[i];
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    return 0;
}