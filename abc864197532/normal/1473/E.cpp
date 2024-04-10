#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 800087, logN = 17, K = 333;

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
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, u--, v--;
        for (int d : {0, 1, 2, 3}) {
            adj[u * 4 + d].eb(v * 4 + d, w);
            adj[v * 4 + d].eb(u * 4 + d, w);
        }
        adj[u * 4].eb(v * 4 + 1, w + w);
        adj[v * 4].eb(u * 4 + 1, w + w);
        adj[u * 4 + 2].eb(v * 4 + 3, w + w);
        adj[v * 4 + 2].eb(u * 4 + 3, w + w);
        adj[u * 4].eb(v * 4 + 2, 0);
        adj[v * 4].eb(u * 4 + 2, 0);
        adj[u * 4 + 1].eb(v * 4 + 3, 0);
        adj[v * 4 + 1].eb(u * 4 + 3, 0);
    }
    build(0, n * 4);
    for (int i = 1; i < n; ++i) cout << min(dis[i * 4], dis[i * 4 + 3]) << ' ';
    cout << endl;
}