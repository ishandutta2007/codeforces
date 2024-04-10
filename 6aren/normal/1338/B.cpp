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

vector<int> g[N];
int dep[N], n;

void dfs(int u, int p) {
    for (int e : g[u]) {
        if (e == p) continue;
        dep[e] = dep[u] + 1;
        dfs(e, u);
    }
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); // or mt19937 for int
long long Rand(long long l, long long r) {
    if (r < l) return 0;
    return l + rng() % (r - l + 1);
}

set<int> ss;
int ra[N];

void dfs2(int u, int p) {
    for (int e : g[u]) {
        if (e == p) continue;
        if (g[e].size() == 1) {
            ss.insert(ra[u]);
            // cout << ra[u] << endl;
        } else {
            int foo = Rand(1, 1e18);
            // cout << foo << endl;
            ss.insert(foo);
            ra[e] = (ra[u] ^ foo);
            dfs2(e, u);
        }
    } 
}



main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int root = 0;
    for (int i = 1; i <= n; i++) if (g[i].size() > 1) root = i;
    dfs(root, 0);
    set<int> s;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) s.insert(dep[i] % 2); 
        if (g[i].size() == 1) root = i;
    }
    int troot = g[root][0];
    ra[troot] = Rand(1, 1e18);
    ss.insert(ra[troot]);
    if (s.size() == 1) cout << 1 << ' ';
    else cout << 3 << ' ';
    dfs2(troot, root);
    int mx = 0;
    mx = max(mx, (int) ss.size());
    ss.clear();
    memset(ra, 0, sizeof(ra));
    ra[troot] = Rand(1, 1e18);
    ss.insert(ra[troot]);
    dfs2(troot, root);
    mx = max(mx, (int) ss.size());
    cout << mx;
    return 0;
}