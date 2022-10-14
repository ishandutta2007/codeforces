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
const int mod = 1e9 + 7, N = 200001, logN = 20, K = 111, C = 7;

vector <int> adj[N];
int dis[N][2], way[N][2];

void build(int s, int n) {
    for (int i = 0; i < n; ++i) dis[i][0] = dis[i][1] = 1 << 30, way[i][0] = way[i][1] = 0;
    priority_queue <pair <int, pii>, vector <pair <int, pii>>, greater <pair <int, pii>>> pq;
    dis[s][0] = 0, way[s][0] = 1;
    pq.emplace(dis[s][0], mp(s, 0));
    int d, v, f;
    while (pq.size()) {
        d = pq.top().X, tie(v, f) = pq.top().Y; pq.pop();
        if (dis[v][f] < d) continue;
        for (int u : adj[v]) {
            for (int ii : {0, 1}) {
                if (dis[u][ii] == d + 1) {
                    way[u][ii] += way[v][f];
                    if (way[u][ii] >= mod)
                        way[u][ii] -= mod;
                    continue;
                }
            }
            if (dis[u][0] > d + 1) {
                dis[u][1] = dis[u][0], way[u][1] = way[u][0];
                if (dis[u][1] != 1 << 30)
                    pq.emplace(dis[u][1], mp(u, 1));
                dis[u][0] = d + 1, way[u][0] = way[v][f];
                pq.emplace(d + 1, mp(u, 0));
            } else if (dis[u][0] != d + 1 && dis[u][1] > d + 1) {
                dis[u][1] = d + 1, way[u][1] = way[v][f];
                pq.emplace(d + 1, mp(u, 1));
            }
        }
    }
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t, --s, --t;
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v, --u, --v;
            adj[u].pb(v), adj[v].pb(u);
        }
        build(s, n);
        int ans = way[t][0];
        if (dis[t][1] == dis[t][0] + 1)
            ans += way[t][1];
        cout << ans % mod << '\n';
        for (int i = 0; i < n; ++i)
            adj[i].clear();
    }
}