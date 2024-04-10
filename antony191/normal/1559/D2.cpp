#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

const char el = '\n';
const int inf = 1000'000'000, mod = 1000000007, mod2 = 998244353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
//#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
//#define firn(i, n) for (int (i) = 1; (i) != (n); (i)++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));
mt19937_64 rnd_64(time(nullptr));

const int N = 100'001;
struct dsu {
    vector<int> p, g[N];
    dsu() {}
    dsu(int n) {
        p.resize(n);
        forn(i, n) {
            p[i] = i;
            g[i] = vector<int>(1, i);
        }
    }
    int getp(int a) {
        return a == p[a] ? a : p[a] = getp(p[a]);
    }
    void unite(int a, int b) {
        a = getp(a), b = getp(b);
        if (g[a].size() < g[b].size())
            swap(a, b);
        p[b] = a;
        for (auto i : g[b])
            g[a].push_back(i);
    }
    vector<int> nodes(int a) {
        return g[getp(a)];
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    dsu t1(n), t2(n);
    forn(i, m1) {
        int u, v;
        cin >> u >> v;
        t1.unite(u - 1, v - 1);
    }
    forn(i, m2) {
        int u, v;
        cin >> u >> v;
        t2.unite(u - 1, v - 1);
    }
    set<int> nq;
    forn(i, n) nq.insert(i);
    for (auto i : t1.nodes(0)) {
        nq.erase(i);
    }
    for (auto i : t2.nodes(0)) {
        if (nq.find(i) != nq.end())
            nq.erase(i);
    }
    vector<pair<int, int>> ans;
    while(!nq.empty()) {
        int v = *nq.begin();
        ans.emplace_back(1, v + 1);
        for (auto i : t1.nodes(v)) {
            if (nq.find(i) != nq.end())
                nq.erase(i);
        }
        for (auto i : t2.nodes(v)) {
            if (nq.find(i) != nq.end())
                nq.erase(i);
        }
        t1.unite(0, v);
        t2.unite(0, v);
    }
    set<int> q1, q2;
    forn(i, n) q1.insert(i), q2.insert(i);
    for (auto i : t1.nodes(0))
        q1.erase(i);
    for (auto i : t2.nodes(0))
        q2.erase(i);
    while(!q1.empty() && !q2.empty()) {
        int v = *q1.begin(), u = *q2.begin();
        ans.emplace_back(v + 1, u + 1);
        for (auto i : t1.nodes(v))
            q1.erase(i);
        for (auto i : t2.nodes(u))
            q2.erase(i);
        t1.unite(v, u);
        t2.unite(v, u);
    }
    cout << (int)ans.size() << el;
    for (auto to : ans)
        cout << to.x << ' ' << to.y << el;
    return 0;
}