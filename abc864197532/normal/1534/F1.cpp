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
const int mod = 1e9 + 7, N = 400001, logN = 20, K = 350;

vector <int> adj[N], radj[N];
int scc[N], _id = 0;
bool vis[N];
vector <int> order;

void rdfs(int v) {
    vis[v] = true;
    for (int u : radj[v]) if (!vis[u]) {
        rdfs(u);
    }
    order.push_back(v);
}

void dfs(int v) {
    scc[v] = _id;
    for (int u : adj[v]) if (scc[u] == -1) {
        dfs(u);
    }
}

void build(int n) {
    _id = 0;
    order.clear();
    for (int i = 0; i < n; ++i) {
        vis[i] = false;
        scc[i] = -1;
    }
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        rdfs(i);
    }
    reverse(order.begin(), order.end());
    for (int v : order) {
        if (scc[v] == -1) {
            dfs(v);
            _id++;
        }
    }
}

void add_edge(int u, int v) {
    if (u == v) return;
    test(u, v);
    adj[u].pb(v);
    radj[v].pb(u);
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <int> v[m];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) if (s[j] == '#') v[j].pb(i);
    }
    auto encode = [&](int i, int j) {
        return i * m + j;
    };
    for (int j = 0; j < m; ++j) for (int i : v[j]) {
        {
            auto it = upper_bound(all(v[j]), i);
            if (it != v[j].end()) add_edge(encode(i, j), encode(*it, j));
        }
        if (j) {
            auto it = lower_bound(all(v[j - 1]), i);
            if (it != v[j - 1].end()) add_edge(encode(i, j), encode(*it, j - 1));
        }
        if (j + 1 < m) {
            auto it = lower_bound(all(v[j + 1]), i);
            if (it != v[j + 1].end()) add_edge(encode(i, j), encode(*it, j + 1));
        }
    }
    for (int j = 0; j < m; ++j) for (int i = 1; i < v[j].size(); ++i) {
        if (v[j][i - 1] + 1 == v[j][i]) {
            add_edge(encode(v[j][i], j), encode(v[j][i - 1], j));
        }
    }
    build(n * m);
    set <int> se;
    for (int j = 0; j < m; ++j) for (int i : v[j]) se.insert(scc[encode(i, j)]);
    for (int i = 0; i < n * m; ++i) for (int j : adj[i]) {
        if (scc[i] == scc[j]) continue;
        se.erase(scc[j]);
    }
    cout << int(se.size()) << endl;
}