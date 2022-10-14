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
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1e5 + 87, logN = 20, K = 111, M = N * 20;

struct edge {
    int u, v;
    lli w;
    bool operator < (const edge &o) {
        return w < o.w;
    }
};

vector <pii> adj[N];
lli dis[N], rt[N];
int dsu[N];

int Find(int x) {
    if (dsu[x] == x)
        return x;
    return dsu[x] = Find(dsu[x]);
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        adj[u].eb(v, w), adj[v].eb(u, w);
    }
    fill(dis, dis + n, 1ll << 60), iota(rt, rt + n, 0);
    cin >> m;
    bool zero = false;
    priority_queue <pair <long long, int>> pq;
    for (int i = 0, x; i < m; ++i)
        cin >> x, --x, dis[x] = 0, pq.emplace(-dis[x], x), zero |= x == 0;
    while (!pq.empty()) {
        lli f; int v; tie(f, v) = pq.top(); pq.pop();
        if (-f > dis[v])
            continue;
        for (auto [u, w] : adj[v]) {
            if (mp(dis[u], rt[u]) > mp(dis[v] + w, rt[v])) {
                tie(dis[u], rt[u]) = mp(dis[v] + w, rt[v]);
                pq.emplace(-dis[u], u);
            }
        }
    }
    vector <edge> E;
    for (int v = 0; v < n; ++v) for (auto [u, w] : adj[v]) if (rt[v] != rt[u])
        E.pb({rt[v], rt[u], dis[u] + dis[v] + w});
    sort(all(E));
    iota(dsu, dsu + n, 0);
    lli ans = 0;
    for (edge &e : E) {
        if (Find(e.u) != Find(e.v))
            dsu[Find(e.u)] = Find(e.v), ans += e.w;
    }
    if (!zero)
        ans += dis[0];
    cout << ans << endl;
}