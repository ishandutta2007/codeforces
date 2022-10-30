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

    bool unite(int v, int u) {
        v = get(v), u = get(u);
        if (v == u)
            return false;
        if (sz[v] > sz[u])
            swap(v, u);
        p[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 3>> edges(m);
    forn (i, 0, m) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--, edges[i][2]--;
    }
    sort(all(edges));
    Dsu dsu(n);
    int components = n;
    forn (i, 0, m) {
        if (edges[i][0] <= k) {
            if (dsu.unite(edges[i][1], edges[i][2]))
                --components;
        }
    }
    if (components == 1) {
        int ans = 2e9;
        forn (i, 0, m)
            chkmin(ans, abs(edges[i][0] - k));
        cout << ans << "\n";
    } else {
        long long ans = 0;
        forn (i, 0, m) {
            if (dsu.unite(edges[i][1], edges[i][2])) {
                ans += edges[i][0] - k;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}