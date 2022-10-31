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
vector <vector <int>> rev_gr;
vector <int> ord;
vector <bool> used;
vector <int> colors;
vector <int> sz;

void dfs1(int v) {
    used[v] = 1;
    for (auto u : gr[v])
        if (!used[u])
            dfs1(u);
    ord.pb(v);
}

void dfs2(int v, int col) {
    sz.back()++;
    colors[v] = col;
    for (auto u : rev_gr[v])
        if (colors[u] == -1)
            dfs2(u, col);
}

void solve() {
    int n;
    cin >> n;
    gr = rev_gr = vector <vector <int>> (n);
    forn (i, 0, n) {
        char c;
        cin >> c;
        int v = i, u;
        if (c == '-') {
            u = (v + 1) % n;
            gr[v].pb(u), rev_gr[u].pb(v);
            swap(v, u);
            gr[v].pb(u), rev_gr[u].pb(v);
            continue;
        }
        if (c == '<') {
            v = (i + 1) % n;
            u = i;
        } else if (c == '>') {
            v = i;
            u = (i + 1) % n;
        }
        gr[v].pb(u), rev_gr[u].pb(v);
        cerr << v << " " << u << "\n";
    }
    used = vector <bool> (n);
    ord.clear();
    forn (i, 0, n)
        if (!used[i])
            dfs1(i);
    reverse(all(ord));
    colors = vector <int> (n, -1);
    int lst_col = 0;
    sz.clear();
    for (int i : ord)
        if (colors[i] == -1) {
            sz.pb(0);
            dfs2(i, lst_col++);
        }
    cerr << colors << "\n";
    int ans = 0;
    forn (i, 0, n)
        if (sz[colors[i]] > 1)
            ++ans;
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