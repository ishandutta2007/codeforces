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
const int mod = 1e9 + 7, abc = 864197532, N = 287, logN = 17;

struct Dinic {
    struct edge {
        int u, v, id;
        long long f;
        edge (int _v, int _id, long long _f) : v(_v), id(_id), f(_f) {}
    };
    vector <vector <edge>> adj;
    vector <int> level;
    int n, s, t;
    Dinic (int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
    }
    void add_edge(int u, int v, long long f) {
        adj[u].push_back(edge(v, adj[v].size(), f));
        adj[v].push_back(edge(u, adj[u].size() - 1, 0));
    }
    bool bfs() {
        level.assign(n, -1);
        queue <int> q;
        q.push(s);
        level[s] = 0;
        while (q.size()) {
            int v = q.front(); q.pop();
            for (edge &e : adj[v]) if (e.f > 0 && level[e.v] == -1) {
                level[e.v] = level[v] + 1;
                q.push(e.v);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int v, long long curf) {
        if (v == t) return curf;
        long long ans = 0;
        for (edge &e : adj[v]) if (e.f > 0 && level[e.v] == level[v] + 1) {
            long long nxtf = dfs(e.v, min(curf, e.f));
            e.f -= nxtf;
            adj[e.v][e.id].f += nxtf;
            curf -= nxtf;
            ans += nxtf;
        }
        if (ans == 0) level[v] = -1;
        return ans;
    }
    long long run() {
        long long ans = 0;
        while (bfs()) {
            ans += dfs(s, 1ll << 60);
        }
        return ans;
    }
};

struct card {
    int p, c, l;
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <bool> prime(200001, true);
    for (int i = 2; i <= 200000; ++i) if (prime[i]) {
        for (int j = i + i; j <= 200000; j += i) {
            prime[j] = false;
        }
    }
    int n, k;
    cin >> n >> k;
    vector <card> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].p >> a[i].c >> a[i].l;
    auto ask = [&](int x) {
        map <int, int> odd, even;
        vector <int> v;
        long long al = 0;
        for (int i = 0; i < n; ++i) if (a[i].l <= x) {
            if (a[i].c & 1) {
                if (a[i].c == 1) odd[a[i].c] = max(odd[a[i].c], a[i].p);
                else odd[a[i].c] += a[i].p;
            } else {
                even[a[i].c] += a[i].p;
            }
            v.pb(a[i].c);
        }
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        Dinic solver(odd.size() + even.size() + 2, 0, 1);
        for (pii A : odd) {
            al += A.Y;
            solver.add_edge(0, lower_bound(all(v), A.X) - v.begin() + 2, A.Y);
        }
        for (pii A : even) {
            al += A.Y;
            solver.add_edge(lower_bound(all(v), A.X) - v.begin() + 2, 1, A.Y);
        }
        for (pii A : odd) for (pii B : even) if (prime[A.X + B.X]) {
            solver.add_edge(lower_bound(all(v), A.X) - v.begin() + 2, lower_bound(all(v), B.X) - v.begin() + 2, 1ll << 60);
        }
        long long ans = al - solver.run();
        return ans >= k;
    };
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = l + r >> 1;
        if (ask(mid)) r = mid;
        else l = mid;
    }
    if (r == n + 1) r = -1;
    cout << r << endl;
}