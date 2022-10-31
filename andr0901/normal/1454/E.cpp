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

class Dsu {
private:
    int n;
    vector <int> p, sz;
public:
    Dsu(int _n) {
        n = _n;
        p.resize(n, -1);
        sz.resize(n, 1);
    }

    int get(int v) {
        if (p[v] == -1)
            return v;
        return p[v] = get(p[v]);
    }

    void unite(int v, int u) {
        v = get(v), u = get(u);
        if (v == u)
            return;
        if (sz[v] > sz[u])
            swap(v, u);
        p[v] = u;
        sz[u] += sz[v];
    }
};

vector <vector <int>> gr;
vector <int> path;

bool find_path(int v, int p, int dest) {
    if (v == dest) {
        path.pb(v);
        return true;
    }
    bool found_dest = false;
    for (int u : gr[v]) {
        if (u == p)
            continue;
        found_dest |= find_path(u, v, dest);
    }
    if (found_dest)
        path.pb(v);
    return found_dest;
}

void solve() {
    int n;
    cin >> n;
    gr = vector <vector <int>> (n);
    path.clear();
    Dsu detect_cycle(n);
    vector <pii> edges(n);
    forn (i, 0, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        edges[i] = {v, u};
        if (detect_cycle.get(v) == detect_cycle.get(u)) {
            cerr << v << " " << u << "\n";
            find_path(v, -1, u);
        } else {
            detect_cycle.unite(v, u);
        }
        gr[v].pb(u), gr[u].pb(v);
    }
    cerr << path << "\n";
    set <int> cycle(path.begin(), path.end());
    Dsu branches(n);
    for (auto [v, u] : edges) {
        if (!(cycle.find(v) != cycle.end() && cycle.find(u) != cycle.end())) {
            branches.unite(v, u);
        }
    }
    vector <int> cnt(n);
    forn (i, 0, n)
        cnt[branches.get(i)]++;
    long long ans = 0;
    forn (i, 0, n) {
        ans += 1LL * cnt[i] * (cnt[i] - 1);
        ans += 1LL * cnt[i] * (n - cnt[i]) * 2;
    }
    cout << ans / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}