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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
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
const int mod = 1e9 + 7, N = 300005, logN = 20, K = 111;

int dsu[N];

void init() {
    for (int i = 0; i < N; ++i) dsu[i] = i;
}

int Find(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = Find(dsu[x]);
}

bool same(int u, int v) {
    return Find(u) == Find(v);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    vector <long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <pii>> adj(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].eb(v, i + 1);
        adj[v].eb(u, i + 1);
    }
    if (accumulate(all(a), 0ll) < 1ll * x * (n - 1)) return cout << "NO\n", 0;
    cout << "YES\n";
    priority_queue <pair <long long, int>> pq;
    for (int i = 0; i < n; ++i) pq.emplace(a[i], i);
    init();
    int dead = 0;
    while (dead < n - 1) {
        long long f;
        int v;
        tie(f, v) = pq.top(); pq.pop();
        if (dsu[v] != v) continue;
        while (!adj[v].empty() && same(v, adj[v].back().X)) adj[v].pop_back();
        assert(!adj[v].empty());
        cout << adj[v].back().Y << endl;
        int u = adj[v].back().X; adj[v].pop_back();
        u = Find(u);
        if (adj[u].size() > adj[v].size()) swap(adj[v], adj[u]);
        for (pii A : adj[u]) adj[v].pb(A);
        adj[u].clear();
        a[v] = a[v] + a[u] - x;
        dsu[Find(u)] = Find(v);
        dead++;
        pq.emplace(a[v], v);
    }
}