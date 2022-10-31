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
vector<int> h;
vector<int> dp;

void calc_dp(int v, int p = -1) {
    if (v == 0)
        h[v] = 0;
    else
        h[v] = h[p] + 1;
    dp[v] = h[v];
    for (int u : gr[v]) {
        calc_dp(u, v);
        chkmax(dp[v], dp[u]);
    }
}

vector<int> path;

void get_path(int v) {
    path.pb(v);
    int mx = -1, mx_idx;
    for (int u : gr[v]) {
        if (dp[u] > mx) {
            mx = dp[u];
            mx_idx = u;
        }
    }
    if (mx != -1) {
        get_path(mx_idx);
    }
}

set<int> diff;
vector<int> ans;
int k;

bool dfs(int v) {
    if (diff.size() >= k) {
        return false;
    }
    ans.pb(v);
    diff.insert(v);
    for (int u : gr[v]) {
        if (dfs(u)) {
            ans.pb(v);
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n >> k;
    gr = vector<vector<int>> (n);
    forn (i, 1, n) {
        int p;
        cin >> p, --p;
        gr[p].pb(i);
    }
    dp = h = vector<int> (n);
    calc_dp(0);
    path.clear();
    get_path(0);
    cerr << path << "\n";
    forn (i, 0, sz(path) - 1) {
        int v = path[i];
        int u = path[i + 1];
        forn (j, 0, gr[v].size()) {
            if (gr[v][j] == u) {
                swap(gr[v][j], gr[v].back());
                gr[v].pop_back();
                break;
            }
        }
    }
    ans.clear();
    diff = set<int>(path.begin(), path.end());
    if (diff.size() >= k) {
        cout << k - 1 << "\n";
        forn (i, 0, k)
            cout << path[i] + 1 << " ";
        cout << "\n";
        return;
    }
    forn (i, 0, sz(path)) {
        dfs(path[i]);
        if (diff.size() >= k) {
            forn (j, i + 1, sz(path)) {
                ans.pb(path[j]);
            }
            break;
        }
    }
    cout << sz(ans) - 1  << "\n";
    for (int i : ans)
        cout << i + 1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}