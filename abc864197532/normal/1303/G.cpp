#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const int mod = 998244353, x = 864197532, N = 150008, logN = 18, K = 500, C = 100;

vector <int> adj[N];
int sz[N];
lli a[N], dep[N], dis1[N], dis2[N], sum[N], ans = 0;
bool vis[N];
vector <vector <int>> cur;

struct line {
    lli m, k;
    line (lli _m, lli _k) : m(_m), k(_k) {}
    lli v(int x) {
        return m * x + k;
    }
};

struct LiChao {
    int l, r, m;
    line best;
    LiChao* ch[2];
    LiChao (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), best(line(0, -1ll << 60)) {
        ch[0] = NULL;
        ch[1] = NULL;
    }
    void insert(line cur) {
        if (r - l == 1) {
            if (best.v(l) < cur.v(l)) swap(best, cur);
        } else {
            if (best.m > cur.m) swap(best, cur);
            if (best.v(m) < cur.v(m)) {
                swap(best, cur);
                if (!ch[0]) ch[0] = new LiChao(l, m);
                ch[0]->insert(cur);
            } else {
                if (!ch[1]) ch[1] = new LiChao(m, r);
                ch[1]->insert(cur);
            }
        }
    }
    lli query(int x) {
        if (r - l == 1) return best.v(x);
        if (x < m && ch[0]) return max(best.v(x), ch[0]->query(x));
        if (x >= m && ch[1]) return max(best.v(x), ch[1]->query(x));
        return best.v(x);
    }
    void release() {
        if (ch[0]) ch[0]->release(), delete ch[0], ch[0] = NULL;
        if (ch[1]) ch[1]->release(), delete ch[1], ch[1] = NULL;
    }
} root(0, N);

void reset() {
    root.release();
    root.best = line(0, -1ll << 60);
}

void dfs1(int v, int pa) {
    sz[v] = 1;
    for (int u : adj[v]) if (u != pa && !vis[u]) {
        dfs1(u, v);
        sz[v] += sz[u];
    }
}

int dfs2(int v, int pa, int n) {
    for (int u : adj[v]) if (u != pa && !vis[u] && sz[u] > n / 2) {
        return dfs2(u, v, n);
    }
    return v;
}

void dfs3(int v, int pa) {
    if (~pa) cur.back().pb(v);
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    sum[v] = ~pa ? sum[pa] + a[v] : a[v];
    dis1[v] = ~pa ? dis1[pa] + a[v] * (dep[v] + 1) : a[v];
    dis2[v] = ~pa ? dis2[pa] + sum[v] : a[v];
    ans = max({ans, dis1[v], dis2[v]});
    for (int u : adj[v]) if (u != pa && !vis[u]) {
        if (!~pa) cur.pb({});
        dfs3(u, v);
    }
    if (!~pa) {
        for (int t : {0, 1}) {
            reset();
            for (vector <int> &V : cur) {
                for (int u : V) {
                    lli tmp = root.query(dep[u]) + dis2[u] - a[v] * (dep[u] + 1);
                    ans = max(ans, tmp);
                }
                for (int u : V) {
                    root.insert(line(sum[u], dis1[u]));
                }
            }
            reverse(all(cur));
        }
        cur.clear();
    }
}

void cd(int v, int pa) {
    dfs1(v, pa);
    int c = dfs2(v, pa, sz[v]);
    vis[c] = true;
    dfs3(c, -1);
    for (int u : adj[c]) if (!vis[u]) {
        cd(u, c);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    fop (i,0,n - 1) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fop (i,0,n) cin >> a[i];
    cd(0, -1);
    cout << ans << endl;
}