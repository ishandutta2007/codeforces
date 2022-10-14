#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl;
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
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 300087, logN = 17, K = 333;

struct edge {
    int v, w, id;
    edge (int _v, int _w, int _id) : v(_v), w(_w), id(_id) {}
    bool operator < (const edge &e) const {
        return w < e.w;
    }
};

vector <edge> adj[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <edge, int>> E;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        adj[u].pb(edge(v, w, i));
        adj[v].pb(edge(u, w, i));
        E.eb(edge(u, w, i), v);
    }
    vector <int> best_edge(n, -1);
    priority_queue <pair <lli, int>, vector <pair <lli, int>>, greater<pair <lli, int>>> pq;
    vector <lli> dis(n, 1ll << 60);
    int s;
    cin >> s, --s;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (pq.size()) {
        lli d;
        int v;
        tie(d, v) = pq.top(); pq.pop();
        if (d > dis[v]) continue;
        for (edge &e : adj[v]) {
            if (dis[e.v] > dis[v] + e.w) {
                dis[e.v] = dis[v] + e.w;
                best_edge[e.v] = e.id;
                pq.emplace(dis[e.v], e.v);
            } else if (dis[e.v] == dis[v] + e.w) {
                if (E[best_edge[e.v]].X.w > e.w) {
                    best_edge[e.v] = e.id;
                }
            }
        }
    }
    vector <int> ans;
    lli tot = 0;
    for (int i = 0; i < n; ++i) if (i ^ s) {
        tot += E[best_edge[i]].X.w;
        ans.pb(best_edge[i] + 1);
    }
    cout << tot << endl;
    printv(ans);
}