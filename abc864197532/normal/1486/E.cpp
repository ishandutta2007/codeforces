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
const int mod = 1e9 + 7, abc = 864197532, N = 10100101, logN = 17, K = 333, INF = 5e8;

vector <pair <int, long long>> adj[N];
long long dis[N];
int path[N];

void build(int s, int n) {
    for (int i = 0; i < n; ++i) path[i] = -1, dis[i] = 1ll << 60;
    priority_queue <pair <long long, int>, vector <pair <long long, int>>, greater <pair <long long, int>>> pq;
    dis[s] = 0;
    pq.push({dis[s], s});
    long long d;
    int v;
    while (pq.size()) {
        tie(d, v) = pq.top(); pq.pop();
        if (dis[v] < d) continue;
        for (auto E : adj[v]) if (dis[E.first] > dis[v] + E.second) {
            dis[E.first] = dis[v] + E.second;
            path[E.first] = v;
            pq.push({dis[E.first], E.first});
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <bool>> is(n, vector <bool>(51, false));
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        adj[u].eb(v + w * n, w * w);
        adj[v + w * n + 50 * n].eb(u, w * w);
        adj[v].eb(u + w * n, w * w);
        adj[u + w * n + 50 * n].eb(v, w * w);
        is[v][w] = is[u][w] = true;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 50; ++j) for (int k = 1; k <= 50; ++k) {
            if (is[i][j] && is[i][k]) {
                adj[i + j * n].eb(i + k * n + 50 * n, 2 * j * k);
            }
        }
    }
    build(0, n * 101);
    for (int i = 0; i < n; ++i) cout << (dis[i] == 1ll << 60 ? -1 : dis[i]) << " \n"[i == n - 1];
}