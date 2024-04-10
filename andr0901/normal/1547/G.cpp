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
vector<int> col;
vector<int> two;
vector<int> inf;
vector<int> ans;

void init_dfs(int v) {
    col[v] = 1;
    for (int u : gr[v]) {
        if (col[u] == 0) {
            init_dfs(u);
        } else if (col[u] == 1) {
            inf.push_back(u);
        } else if (col[u] == 2) {
            two.pb(u);
        }
    }
    col[v] = 2;
}

void dfs_inf(int v) {
    ans[v] = -1;
    for (int u : gr[v]) {
        if (ans[u] == 1) {
            dfs_inf(u);
        }
    }
}

void dfs_two(int v) {
    ans[v] = 2;
    for (int u : gr[v]) {
        if (ans[u] == 1) {
            dfs_two(u);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    gr = vector<vector<int>>(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        gr[v].pb(u);
    }
    col = vector<int>(n);
    two.clear(), inf.clear();
    init_dfs(0);
    ans = vector<int>(n);
    forn (i, 0, n) {
        if (col[i]) {
            ans[i] = 1;
        }
    }
    for (int v : inf) {
        dfs_inf(v);
    }
    for (int v : two) {
        if (ans[v] == 1) {
            dfs_two(v);
        }
    }
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