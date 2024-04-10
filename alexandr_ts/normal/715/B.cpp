#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const int N = 1e3 + 10;
const int M = 1e4 + 10;
const ll INF = 1e15 + 10;

vector<pair<ll, int> > g[2][N];
ll dist[N];

ll dijkstra(int n, int st, int en) {
    fill(dist, dist + n, INF);
    dist[st] = 0;
    set<pair<ll, int> > s;
    for (int i = 0; i < n; i++)
        s.insert({dist[i], i});
    while (s.size()) {
        auto t = *s.begin();
        s.erase(s.begin());
        if (t.first == INF)
            break;
        int v = t.second;
        for (int i = 0; i < 2; i++)
            for (auto ed: g[i][v]) {
                ll u = ed.second;
                if (s.count({dist[u], u})) {
                    s.erase({dist[u], u});
                    dist[u] = min(dist[u], dist[v] + ed.first);
                    s.insert({dist[u], u});
                }
            }
    }
    return dist[en];
}

vector<pair<ll, int> > g3[N];

void fill2(ll val, int cntFirst, int n) {
    for (int i = 0; i < n; i++)
        g3[i].clear();

    for (int i = 0; i < n; i++) {
        for (auto ed: g[1][i])
            if (ed.second > i) {
                g3[i].pb({val, ed.second});
                if (cntFirst) {
                    g3[i].back().first++;
                    cntFirst--;
                }
                g3[ed.second].pb({g3[i].back().first, i});
            }
    }
    for (int i = 0; i < n; i++)
        g[1][i] = g3[i];
}

void solve() {
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        if (w) {
            g[0][v].pb({w, u});
            g[0][u].pb({w, v});
        } else {
            g[1][v].pb({w, u});
            g[1][u].pb({w, v});
        }
    }
    fill2(INF, 0, n);
    ll initAns = dijkstra(n, s, t);

    if (initAns < L) {
        cout << "NO";
        return;
    }

    ll tl = 1, tr = 1e9 + 10;
    while (tr - tl > 1) {
        ll tm = (tl + tr) / 2;
        fill2(tm, 0, n);
        ll curAns = dijkstra(n, s, t);
        if (curAns <= L) {
            tl = tm;
        } else {
            tr = tm;
        }
    }

    int tl2 = 0, tr2 = 2 * m + 1;
    while (tr2 - tl2 > 1) {
        int tm2 = (tl2 + tr2) / 2;
        fill2(tl, tm2, n);
        ll curAns = dijkstra(n, s, t);
        if (curAns <= L) {
            tl2 = tm2;
        } else {
            tr2 = tm2;
        }
    }

    fill2(tl, tl2, n);

    ll finalAns = dijkstra(n, s, t);

    if (finalAns != L) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++)
            for (auto u: g[j][i])
                if (u.second > i)
                    cout << i << " " << u.second << " " << u.first << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();
}