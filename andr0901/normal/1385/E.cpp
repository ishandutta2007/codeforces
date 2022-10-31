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
vector <int> used;
vector <int> ord;
bool ok = true;

void dfs(int v) {
    used[v] = 1;
    for (int u : gr[v]) {
        if (used[u] == 1)
            ok = false;
        if (!used[u])
            dfs(u);
    }
    used[v] = 2;
    ord.pb(v);
}

void solve() {
    int n, m;
    cin >> n >> m;
    gr = vector <vector <int>> (n);
    vector <pii> unoriened;
    forn (i, 0, m) {
        int type, v, u;
        cin >> type >> v >> u, --v, --u;
        if (type)
            gr[v].pb(u);
        else
            unoriened.eb(v, u);
    }
    ord.clear();
    ok = true;
    used = vector <int> (n);
    forn (i, 0, n)
        if (!used[i])
            dfs(i);
    if (!ok) {
        cout << "NO\n";
        return;
    }
    vector <int> get(n);
    reverse(all(ord));
    forn (i, 0, n)
        get[ord[i]] = i;
    cout << "YES\n";
    forn (i, 0, n)
        for (int j : gr[i])
            cout << i + 1 << " " << j + 1 << "\n";
    for (auto [v, u] : unoriened) {
        if (get[v] > get[u])
            swap(v, u);
        cout << v + 1 << " " << u + 1 << "\n";
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