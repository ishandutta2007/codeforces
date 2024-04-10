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

vector <vector <pii>> gr;
vector <int> sz;
vector <long long> a;
vector <int> ord;

long long s;

int dfs(int v, int p, long long cur) {
    if (p != -1 && sz(gr[v]) == 1) {
        a[v] = cur;
        return sz[v] = 1;
    }
    for (auto [u, c] : gr[v])
        if (u != p) {
            sz[v] += dfs(u, v, cur + c);
        }
    return sz[v];
}

void solve() {
    int n;
    cin >> n;
    cin >> s;
    vector <vector <int>> _e;
    gr = vector <vector <pii>> (n);
    forn (i, 1, n) {
        int v, u, w;
        cin >> v >> u >> w, --v, --u;
        gr[v].eb(u, w), gr[u].eb(v, w);
        _e.pb({w, v, u});
    }
    a = vector <long long> (n);
    sz = vector <int> (n);
    dfs(0, -1, 0);
    set <pair <long long, int>> e;
    auto calc = [&](int i) {
        int diff = _e[i][0] - (_e[i][0] / 2);
        return diff * sz[_e[i][1]];
    };
    forn (i, 0, sz(_e)) {
        if (sz[_e[i][1]] > sz[_e[i][2]])
            swap(_e[i][1], _e[i][2]);
        e.insert({calc(i), i});
    }
    long long sum = 0;
    forn (i, 0, n)
        sum += a[i];
    /*cerr << sz << "\n";
    cerr << sum << " ";*/
    int ans = 0;
    while (!e.empty() && sum > s) {
        int i = (--e.end())->sc;
        e.erase(--e.end());
        sum -= calc(i);
        _e[i][0] /= 2;
        e.insert({calc(i), i});
        ++ans;
        //cerr << sum << " ";
    }
    cout << ans << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}