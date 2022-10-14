#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17;

vector <int> adj[N];
vector <int> adj2[N];
vector <vector <int>> newnode;
bool vis[N];
int p[N], in[N], deg[N], out[N], cnt = 0;
pii id[N];

void dfs(int v) {
    vis[v] = true;
    cnt++;
    id[v] = mp(newnode.size() - 1, newnode.back().size());
    newnode.back().pb(v);
    for (int u : adj2[v]) {
        if (vis[u]) {
            cout << 0 << endl;
            exit(0);
        }
        dfs(u);
    }
}

vector <int> toposort(int n) {
    vector <int> d(n), ans;
    queue <int> q;
    for (int i = 0; i < n; ++i) {
        d[i] = deg[i];
        if (d[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int v = q.front(); q.pop();
        ans.push_back(v);
        for (int u : adj[v]) {
            d[u]--;
            if (d[u] == 0) q.push(u);
        }
    }
    if (ans.size() != n) {
        ans.clear();
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj2[u].pb(v);
        in[v]++;
        out[u]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (in[i] > 1 || out[i] > 1) {
            cout << 0 << endl;
            exit(0);
        }
    }
    for (int i = 1; i <= n; ++i) if (!vis[i] && !in[i]) newnode.pb({}), dfs(i);
    if (cnt != n) {
        cout << 0 << endl;
        exit(0);
    }
    for (int i = 1; i <= n; ++i) if (p[i]) {
        if (id[p[i]].X == id[i].X) {
            if (id[p[i]].Y > id[i].Y) {
                cout << 0 << endl;
                exit(0);
            }
        } else {
            adj[id[p[i]].X].pb(id[i].X);
            deg[id[i].X]++;
        }
    }
    vector <int> o = toposort(newnode.size());
    if (o.empty()) {
        cout << 0 << endl;
    } else {
        vector <int> ans;
        for (int id : o) {
            for (int v : newnode[id]) {
                ans.pb(v);
            }
        }
        printv(ans);
    }
}