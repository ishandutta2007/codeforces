#pragma GCC optimize("Ofast")
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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <vector <int>> gr;

void bfs(int s, vector <int>& dst) {
    dst = vector <int> (sz(gr), 1e9);
    dst[s] = 0;
    deque <int> q = {s};
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (int u : gr[v]) {
            if (dst[v] + 1 < dst[u]) {
                dst[u] = dst[v] + 1;
                q.pb(u);
            }
        }
    } 
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c, --a, --b, --c;
    vector <int> e(m);
    cin >> e;
    sort(all(e));
    gr = vector <vector <int>> (n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    vector <int> dst_a, dst_b, dst_c;
    bfs(a, dst_a), bfs(b, dst_b), bfs(c, dst_c);
    vector <ll> pref_e(3 * m + 5, 1e18);
    pref_e[0] = 0;
    forn (i, 0, m)
        pref_e[i + 1] = pref_e[i] + e[i];
    ll ans = 1e18;
    forn (i, 0, n)
        chkmin(ans, pref_e[dst_a[i] + dst_b[i] + dst_c[i]] + pref_e[dst_b[i]]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}