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

string fs = "Alice", sc = "Bob";

vector <vector <int>> gr;

void dfs(int v, int p, vector <int>& dst) {
    if (p == -1)
        dst[v] = 0;
    for (int u : gr[v])
        if (u != p) {
            dst[u] = dst[v] + 1;
            dfs(u, v, dst);
        }
}

pii diam(int v, int p = -1) {
    pii ans = {0, v};
    for (int u : gr[v])
        if (u != p) {
            auto t = diam(u, v);
            t.fs++;
            chkmax(ans, t);
        }
    return ans;
}

void solve() {
    int n, a, b, speed_a, speed_b;
    cin >> n >> a >> b >> speed_a >> speed_b;
    --a, --b;
    gr = vector <vector <int>> (n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    if (speed_b <= 2 * speed_a) {
        cout << fs << "\n";
        return;
    }
    vector <int> dst_a(n);
    dfs(a, -1, dst_a);
    if (dst_a[b] <= speed_a) {
        cout << fs << "\n";
        return;
    }
    pii d = diam(diam(0, -1).sc, -1);
    if (d.fs > 2 * speed_a)
        cout << sc;
    else
        cout << fs;
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