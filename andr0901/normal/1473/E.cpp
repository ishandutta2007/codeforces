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

#define int long long

constexpr int INF = 1e18 + 5;

vector<vector<pii>> gr;

void solve() {
    int n, m;
    cin >> n >> m;
    gr = vector<vector<pii>> (n);
    forn (i, 0, m) {
        int v, u, w;
        cin >> v >> u >> w, --v, --u;
        gr[v].eb(u, w);
        gr[u].eb(v, w);
    }
    vector<vector<vector<int>>> dst(n, vector<vector<int>> (2, vector<int> (2, INF)));
    dst[0][0][0] = 0;
    set<pair <pii, pii>> s;
    forn (i, 0, n)
        forn (j, 0, 2)
            forn (k, 0, 2)
                s.insert({{dst[i][j][k], j}, {k, i}});
    while (!s.empty()) {
        auto t = *s.begin();
        s.erase(s.begin());
        int d = t.fs.fs, minus = t.fs.sc, plus = t.sc.fs, v = t.sc.sc;
        for (auto [u, w] : gr[v]) {
            if (!minus) {
                int new_d = d;
                int new_minus = true;
                int new_plus = plus;
                if (new_d < dst[u][new_minus][new_plus]) {
                    s.erase({{dst[u][new_minus][new_plus], new_minus}, {new_plus, u}});
                    dst[u][new_minus][new_plus] = new_d;
                    s.insert({{dst[u][new_minus][new_plus], new_minus}, {new_plus, u}});
                }
            }
            if (!plus) {
                int new_d = d + 2 * w;
                int new_minus = minus;
                int new_plus = true;
                if (new_d < dst[u][new_minus][new_plus]) {
                    s.erase({{dst[u][new_minus][new_plus], new_minus}, {new_plus, u}});
                    dst[u][new_minus][new_plus] = new_d;
                    s.insert({{dst[u][new_minus][new_plus], new_minus}, {new_plus, u}});
                }
            }
            if (!plus && !minus) {
                int new_d = d + w;
                int new_minus = true;
                int new_plus = true;
                if (new_d < dst[u][new_minus][new_plus]) {
                    s.erase({{dst[u][new_minus][new_plus], new_minus}, {new_plus, u}});
                    dst[u][new_minus][new_plus] = new_d;
                    s.insert({{dst[u][new_minus][new_plus], new_minus}, {new_plus, u}});
                }
            }
            if (true) {
                int new_d = d + w;
                int new_minus = minus;
                int new_plus = plus;
                if (new_d < dst[u][new_minus][new_plus]) {
                    s.erase({{dst[u][new_minus][new_plus], new_minus}, {new_plus, u}});
                    dst[u][new_minus][new_plus] = new_d;
                    s.insert({{dst[u][new_minus][new_plus], new_minus}, {new_plus, u}});
                }
            }
        }
    }
    forn (i, 1, n)
        cout << dst[i][1][1] << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t --> 0)
        solve();
    return 0;
}