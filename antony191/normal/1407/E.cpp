#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1000'000'000, mod = 1000'000'007;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

const int N = 500'001;
vector<pair<int, char>> g[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int v, u, t;
        cin >> u >> v >> t;
        v--; u--;
        g[v].emplace_back(u, t);
    }
    vector<int> d[2];
    d[0].assign(n, n); d[1].assign(n, n);
    d[0][n - 1] = d[1][n - 1] = 0;
    set<pair<int, int>> q;
    q.emplace(0, n - 1);
    vector<int> c(n);
    while(!q.empty()) {
        int v = q.begin()->y;
        q.erase(q.begin());
        int td = max(d[0][v], d[1][v]);
        if (td == d[1][v]) c[v] = 1;
        for (auto to : g[v]) {
            if (td + 1 < d[to.y][to.x]) {
                if (max(d[0][to.x], d[1][to.x]) < n) q.erase(pair<int, int>{max(d[0][to.x], d[1][to.x]), to.x});
                d[to.y][to.x] = td + 1;
                q.emplace(max(d[0][to.x], d[1][to.x]), to.x);
            }
        }
    }
    int td = max(d[0][0], d[1][0]);
    cout << (td == n ? -1 : td) << el;
    forn(i, n) cout << c[i];
    cout << el;
    return 0;
}