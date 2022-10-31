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

vector <vector <int>> gr;

vector <int> sz;

int dfs_sz(int v, int p = -1) {
    sz[v] = 1;
    for (int u : gr[v])
        if (u != p)
            sz[v] += dfs_sz(u, v);
    return sz[v];
}

void find_ones(int v, int p, int banned, int& ans) {
    if (gr[v].size() == 1)
        ans = v;
    for (int u : gr[v])
        if (u != p && u != banned)
            find_ones(u, v, banned, ans);
}

void solve() {
    int n;
    cin >> n;
    gr = vector <vector <int>> (n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    sz = vector <int> (n);
    dfs_sz(0, -1);
    vector <int> centroids;
    forn (v, 0, n) {
        int mx = 0;
        for (int u : gr[v])
            if (sz[u] < sz[v])
                chkmax(mx, sz[u]);
        if (mx <= n / 2 && n - sz[v] <= n / 2)
            centroids.pb(v);
    }
    cerr << centroids << "\n";
    if (sz(centroids) == 1) {
        cout << gr[0][0] + 1 << " 1\n";
        cout << gr[0][0] + 1 << " 1\n";
    } else {
        int ans_1 = -1, ans_2 = -1;
        find_ones(centroids[0], -1, centroids[1], ans_1);
        find_ones(centroids[1], -1, centroids[0], ans_2);
        if (ans_1 != -1) {
            cout << gr[ans_1][0] + 1 << " " << ans_1 + 1 << "\n";
            cout << ans_1 + 1 << " " << centroids[1] + 1 << "\n";
        } else {
            cout << gr[ans_2][0] + 1 << " " << ans_2 + 1 << "\n";
            cout << ans_2 + 1 << " " << centroids[0] + 1 << "\n";            
        }
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