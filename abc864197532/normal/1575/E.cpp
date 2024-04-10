/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 200087, logN = 20, K = 111;

vector <pii> adj[N];
vector <int> a;
int sz[N], k;
bool vis[N];

void dfs_sz(int v, int pa) {
    sz[v] = 1;
    for (auto [u, t] : adj[v]) if (u != pa && !vis[u]) {
        dfs_sz(u, v);
        sz[v] += sz[u];
    }
}

int dfs_cen(int v, int pa, int n) {
    for (auto [u, t] : adj[v]) if (u != pa && !vis[u] && sz[u] > n / 2) {
        return dfs_cen(u, v, n);
    }
    return v;
}

lli sum[N], chg[N];

lli val[N][4];
vector <int> mov[4];
void add(int p, lli v, int t) {
    p++;
    for (int i = p; i < N; i += i & (-i))
        (val[i][t] += v) %= mod, mov[t].pb(i);
}
lli query(int p, int t) {
    p++;
    lli ans = 0;
    for (int i = p; i > 0; i -= i & (-i)) {
       (ans += val[i][t]) %= mod;
    }
    return ans;
}
void rollback(int t) {
    while (!mov[t].empty()) {
        val[mov[t].back()][t] = 0, mov[t].pop_back();
    }
}

vector <int> now;
lli ans = 0;

void dfs_ans(int v, int pa, int cc, int c) {
    if (~pa)
        now.pb(v);
    sum[v] = ((~pa ? sum[pa] : 0) + a[v]) % mod;
    for (auto [u, t] : adj[v]) if (u != pa && !vis[u]) {
        chg[u] = chg[v] + (!~pa ? 0 : (cc != t));
        dfs_ans(u, v, t, c);
        if (!~pa) {
            for (int v : now) {
                if (chg[v] <= k)
                    (ans += sum[v]) %= mod;
                (ans += query(k - chg[v], t) + query(k - chg[v], t | 2) * (sum[v] + mod - a[c]) % mod) %= mod;
                (ans += query(k - chg[v] - 1, t ^ 1) + query(k - chg[v] - 1, (t ^ 1) | 2) * (sum[v] + mod - a[c]) % mod) %= mod;
            }
            for (int v : now) {
                add(chg[v], sum[v], t);
                add(chg[v], 1, t | 2);
            }
            now.clear();
        }
    }
}

void dfs_cd(int v, int pa) {
    dfs_sz(v, pa);
    int c = dfs_cen(v, pa, sz[v]);
    vis[c] = true;
    chg[c] = 0;
    dfs_ans(c, -1, -1, c);
    rollback(0), rollback(1), rollback(2), rollback(3);
    for (auto [u, t] : adj[c]) if (!vis[u]) {
        dfs_cd(u, c);
    }
}

int main () {
    owo;
    int n;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i], (ans += a[i]) %= mod;
    for (int i = 0, u, v, t; i < n - 1; ++i) {
        cin >> u >> v >> t, --u, --v;
        adj[u].eb(v, t);
        adj[v].eb(u, t);
    }
    dfs_cd(0, -1);
    cout << ans << endl;
}