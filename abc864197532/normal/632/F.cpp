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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 3001, logN = 20, K = 111;

struct edge {
    int u, v, w;
    bool operator < (const edge& o) {
        return w < o.w;
    }
};

int dsu[N];

void init() {
    for (int i = 0; i < N; ++i) dsu[i] = i;
}

int Find(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = Find(dsu[x]);
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;
    dsu[u] = v;
    return true;
}

vector <pii> adj[N];
int dis[N][N];

void dfs(int st, int v, int pa) {
    for (auto [u, w] : adj[v]) if (u != pa) {
        dis[st][u] = max(dis[st][v], w);
        dfs(st, u, v);
    }
}

int main () {
    owo;
    int n;
    cin >> n;
    vv <int> a(n, n, 0);
    vector <edge> E;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
    for (int i = 0; i < n; ++i) {
        if (a[i][i] != 0) return cout << "NOT MAGIC\n", 0;
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] != a[j][i]) return cout << "NOT MAGIC\n", 0;
            E.pb({i, j, a[i][j]});
        }
    }
    sort(all(E));
    init();
    for (edge &e : E) if (Union(e.u, e.v)) {
        adj[e.u].eb(e.v, e.w);
        adj[e.v].eb(e.u, e.w);
    }
    for (int i = 0; i < n; ++i) dfs(i, i, -1);
    bool is = true;
    for (edge &e : E) {
        is &= dis[e.u][e.v] == e.w;
    }
    if (!is) cout << "NOT ";
    cout << "MAGIC\n";
}