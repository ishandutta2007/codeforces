#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
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
const int mod = 1e9 + 7, abc = 864197532, N = 300101, logN = 19, K = 333, INF = 5e8;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> ans(m), deg(n);
    vector <set <int>> adj(n);
    vector <pii> edge;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++;
        deg[v]++;
        edge.eb(u, v);
    }
    vector <bool> ok(n, true);
    set <pii> s;
    for (int i = 0; i < n; ++i) s.insert({deg[i], i});
    auto del_deg = [&](int u, int v) {
        adj[u].erase(v);
        s.erase({deg[u], u});
        deg[u]--;
        s.insert({deg[u], u});
    };
    auto update_set = [&]() {
        while (!s.empty() && s.begin()->X < k) {
            int d, v;
            tie(d, v) = *s.begin(); s.erase(s.begin());
            for (int u : adj[v]) {
                del_deg(u, v);
            }
            adj[v].clear();
        }
    };
    update_set();
    for (int i = m - 1, u, v; ~i; --i) {
        ans[i] = int(s.size());
        tie(u, v) = edge[i];
        if (adj[u].count(v)) del_deg(u, v);
        if (adj[v].count(u)) del_deg(v, u);
        update_set();
    }
    printv(ans);
}