//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

void dijkstra(int st, const vector <vector <pii>>& gr, vector <int>& dst) {
    dst.resize(sz(gr), 1e9);
    set <pii> s;
    s.emplace(0, st);
    dst[st] = 0;
    while (!s.empty()) {
        int v = s.begin() -> sc;
        s.erase(s.begin());
        for (pii u : gr[v]) {
            if (dst[v] + u.sc < dst[u.fs]) {
                s.erase({dst[u.fs], u.fs});
                dst[u.fs] = dst[v] + u.sc;
                s.emplace(dst[u.fs], u.fs);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <pii>> gr(n);
    vector <tuple <int, int, int>> edges(m);
    forn (i, 0, m) {
        int v, u, w;
        cin >> v >> u >> w, --v, --u;
        gr[v].eb(u, w), gr[u].eb(v, w);
        edges[i] = {v, u, w};
    }
    vector <vector <int>> dst(n);
    forn (i, 0, n) {
        dijkstra(i, gr, dst[i]);
        cerr << dst[i] << "\n";
    }
    vector <pii> routes(k);
    forn (i, 0, k) {
        cin >> routes[i].fs >> routes[i].sc;
        routes[i].fs--, routes[i].sc--;
    }
    long long ans = 1e18;;
    for (auto [v, u, w] : edges) {
        long long cur_sum = 0;
        for (auto [from, to] : routes) {
            int mn = dst[from][to];
            chkmin(mn, dst[from][v] + dst[u][to]);
            chkmin(mn, dst[from][u] + dst[v][to]);
            cur_sum += mn;
        }
        cerr << cur_sum << "\n";
        chkmin(ans, cur_sum);
    }
    cout << ans;
    return 0;
}