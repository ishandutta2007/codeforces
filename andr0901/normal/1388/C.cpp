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

vector <vector <int>> gr;

vector <int> sz;
vector <int> p, h;
vector <int> good, bad;

bool ok = true;

void dfs(int v, int par) {
    sz[v] = p[v];
    for (int u : gr[v])
        if (u != par) {
            dfs(u, v);
            sz[v] += sz[u];
        }
    cerr << v << " " << sz[v] << "\n";
    if ((h[v] + sz[v] + 1000000000) % 2)
        ok = false;
    good[v] = (h[v] + sz[v]) / 2;
    bad[v] = good[v] - h[v];
    if (!(0 <= good[v] && good[v] <= sz[v]) ||
        !(0 <= bad[v] && bad[v] <= sz[v]))
        ok = false;
    int sum_good = 0, sum_bad = 0;
    for (int u : gr[v])
        if (u != par) {
            sum_good += good[u];
            sum_bad += bad[u];
        }
    if (p[v] != sz[v] - sum_good - sum_bad)
        ok = false;
    if (good[v] < sum_good)
        ok = false;
    cerr << v << " " << ok << "\n";
}

// h[v] = good[v] - bad[v]
// good[v] + bad[v] = sz[v]
// 2 good = h + sz
// bad = good - h

// v_g - v_b -> u_g - u_b + t

void solve() {
    int n, m;
    cin >> n >> m;
    p = h = sz = good = bad = vector <int> (n + 1);
    forn (i, 0, n)
        cin >> p[i];
    forn (i, 0, n)
        cin >> h[i];
    gr = vector <vector <int>> (n + 1);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    ok = true;
    h[n] = m;
    gr[n].pb(0);
    dfs(n, -1);
    cerr << sz << "\n" << good << "\n" << bad << "\n";
    cout << (ok ? "YES" : "NO") << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();   
    return 0;
}