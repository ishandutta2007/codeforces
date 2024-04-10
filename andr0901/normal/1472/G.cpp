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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u);
    }
    vector<int> dst(n, 1e9);
    vector<int> ord;
    deque<int> q = {0};
    dst[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        ord.pb(v);
        for (int u : gr[v]) {
            if (dst[v] + 1 < dst[u]) {
                dst[u] = dst[v] + 1;
                q.pb(u);
            }
        }
    }
    vector<int> dp(n);
    reverse(all(ord));
    cerr << ord << "\n";
    for (int v : ord) {
        dp[v] = dst[v];
        for (int u : gr[v])
            if (dst[u] > dst[v])
                chkmin(dp[v], dp[u]);
            else
                chkmin(dp[v], dst[u]);
    }
    cout << dp << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}