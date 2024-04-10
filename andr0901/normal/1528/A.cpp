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

vector<vector<int>> gr;
vector<int> l, r;
vector<long long> dp_l;
vector<long long> dp_r;

void dfs(int v, int p = -1) {
    for (int u : gr[v]) {
        if (u != p) {
            dfs(u, v);
            dp_l[v] += max(
                dp_l[u] + abs(l[v] - l[u]),
                dp_r[u] + abs(l[v] - r[u])
            );
            dp_r[v] += max(
                dp_l[u] + abs(r[v] - l[u]),
                dp_r[u] + abs(r[v] - r[u])
            );
        }
    }
}

void solve() {
    int n;
    cin >> n;
    gr = vector<vector<int>>(n);
    l = r = vector<int>(n);
    forn (i, 0, n) {
        cin >> l[i] >> r[i];
    }
    vector<pii> edges;
    edges.reserve(n - 1);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        gr[v].pb(u), gr[u].pb(v);
        edges.eb(v, u);
    }
    dp_l = dp_r = vector<long long>(n);
    dfs(0);
    cerr << dp_l << "\n" << dp_r << "\n\n";
    cout << max(dp_l[0], dp_r[0]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}