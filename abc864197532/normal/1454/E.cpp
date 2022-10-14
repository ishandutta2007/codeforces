#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200004, logN = 18, K = 500, C = 100;

vector <int> adj[N];
bool vis[N]{};
int p[N];
int a, b;

void dfs(int v, int pa) {
    p[v] = pa;
    vis[v] = true;
    for (int u : adj[v]) if (u != pa) {
        if (vis[u]) {
            a = v, b = u;
        } else dfs(u, v);
    }
}

int dfs2(int v, int pa) {
    int cnt = 1;
    for (int u : adj[v]) if (u != pa && !vis[u]) {
        cnt += dfs2(u, v);
    }
    return cnt;
}

void solve() {
    int n, u, v;
    cin >> n;
    fop (i,0,n) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    fop (i,0,n) vis[i] = false;
    v = b;
    vis[a] = vis[b] = true;
    vector <int> cur = {a, b};
    while (p[v] != a) {
        v = p[v];
        vis[v] = true;
        cur.pb(v);
    }
    lli ans = 1ll * n * (n - 1);
    for (int i : cur) {
        int c = dfs2(i, -1);
        ans += 1ll * c * (n - c);
    }
    cout << ans / 2 << endl;
    fop (i,0,n) adj[i].clear(), vis[i] = false, p[i] = -1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}