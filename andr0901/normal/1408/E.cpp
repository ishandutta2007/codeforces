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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    cin >> a >> b;
    vector <vector <int>> edges;
    long long ans = 0;
    forn (i, 0, n) {
        int k;
        cin >> k;
        forn (j, 0, k) {
            int t;
            cin >> t, --t;
            edges.pb({a[i] + b[t], i, t + n});
            ans += edges.back()[0];
        }
    }
    sort(rall(edges));
    Dsu d(n + m);
    forn (i, 0, sz(edges)) {
        int w = edges[i][0], v = edges[i][1], u = edges[i][2];
        cerr << w << " " << v << " " << u << "\n";
        if (d.get(v) != d.get(u)) {
            ans -= w;
            d.unite(v, u);
        }
    }
    cout << ans;
    return 0;
}