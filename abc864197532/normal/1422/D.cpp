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
const int mod = 1e9 + 7, abc = 864197532, N = 300087, logN = 17, K = 333;

vector <pii> adj[N];
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
    int m, n, sx, sy, fx, fy;
    cin >> m >> n >> sx >> sy >> fx >> fy;
    vector <pair <pii, int>> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].X, p[i].Y = i + 2;
    sort(all(p), [&](pair<pii, int> a, pair<pii, int> b) {
        return a.X.X < b.X.X;
    });
    for (int i = 1; i < n; ++i) {
        adj[p[i - 1].Y].eb(p[i].Y, p[i].X.X - p[i - 1].X.X);
        adj[p[i].Y].eb(p[i - 1].Y, p[i].X.X - p[i - 1].X.X);
    }
    sort(all(p), [&](pair<pii, int> a, pair<pii, int> b) {
        return a.X.Y < b.X.Y;
    });
    for (int i = 1; i < n; ++i) {
        adj[p[i - 1].Y].eb(p[i].Y, p[i].X.Y - p[i - 1].X.Y);
        adj[p[i].Y].eb(p[i - 1].Y, p[i].X.Y - p[i - 1].X.Y);
    }
    for (int i = 0; i < n; ++i) {
        adj[0].eb(p[i].Y, min(abs(sx - p[i].X.X), abs(sy - p[i].X.Y)));
        adj[p[i].Y].eb(0, min(abs(sx - p[i].X.X), abs(sy - p[i].X.Y)));
        adj[1].eb(p[i].Y, abs(fx - p[i].X.X) + abs(fy - p[i].X.Y));
        adj[p[i].Y].eb(1, abs(fx - p[i].X.X) + abs(fy - p[i].X.Y));
        if (mp(sx, sy) == p[i].X) adj[0].eb(p[i].Y, 0), adj[p[i].Y].eb(0, 0);
        if (mp(fx, fy) == p[i].X) adj[1].eb(p[i].Y, 0), adj[p[i].Y].eb(1, 0);
    }
    build(0, n + 2);
    lli ans = abs(sx - fx) + abs(sy - fy);
    cout << min(ans, dis[1]) << endl;
}