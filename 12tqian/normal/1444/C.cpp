#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define resz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define f1r(i, a, b) for(int i = (a); i < (b); ++i)
#define f0r(i, a) f1r(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a : x)

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1, T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T, SZ>& a);
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class T, class... Ts> void re(T& t, Ts&... ts) {
        re(t); re(ts...); }
    template<class T> void re(complex<T>& x) { T a, b; re(a, b); x = cd(a, b); }
    template<class T1, class T2> void re(pair<T1, T2>& p) { re(p.f, p.s); }
    template<class T> void re(vector<T>& a) { F0R(i, sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T, SZ>& a) { F0R(i, SZ) re(a[i]); }
}

using namespace input;

namespace output {
    void pr(int x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(ll x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(ld x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { pr(x ? "true" : "false"); }
    template<class T> void pr(const complex<T>& x) { cout << x; }
    template<class T1, class T2> void pr(const pair<T1, T2>& x);
    template<class T> void pr(const T& x);
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
        pr(t); pr(ts...); }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{", x.f, ", ", x.s, "}"); }
    template<class T> void pr(const T& x) {
        pr("{"); // const iterator needed for vector<bool>
        bool fst = 1; for (const auto& a: x) pr(!fst ? ", " : "", a), fst = 0;
        pr("}"); }
    void ps() { pr("\n"); } // print w/ spaces
    template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); }
    void pc() { pr("]\n"); } // debug w/ commas
    template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(), "r", stdin); }
    void setOut(string s) { freopen(s.c_str(), "w", stdout); }
    void setIO(string s = "") {
        cin.sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s + ".in"), setOut(s + ".out"); }
    }
}

using namespace io;

const int MOD = 1e9 + 7; // 998244353;
const ld PI = acos((ld) -1);

typedef decay<decltype(MOD)>::type T;
struct mi {
    T val;
    explicit operator T() const { return val; }
    mi() { val = 0; }
    mi(const ll& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend ostream& operator << (ostream& os, const mi& a) { return os << a.val; }
    friend void pr(const mi& a) { pr(a.val); }
    friend void re(mi& a) { ll x; re(x); a = mi(x); }
    friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator != (const mi& a, const mi& b) { return !(a == b); }
    friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
    friend bool operator > (const mi& a, const mi& b) { return a.val > b.val; }
    friend bool operator <= (const mi& a, const mi& b) { return a.val <= b.val; }
    friend bool operator >= (const mi& a, const mi& b) { return a.val >= b.val; }
    mi operator - () const { return mi(-val); }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator *= (const mi& m) { val = (ll) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator /= (const mi& m) { return (*this) *= inv(m); }
    friend mi operator + (mi a, const mi& b) { return a += b; }
    friend mi operator - (mi a, const mi& b) { return a -= b; }
    friend mi operator * (mi a, const mi& b) { return a *= b; }
    friend mi operator / (mi a, const mi& b) { return a /= b; }
};

typedef pair<mi, mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
struct DSUrb {
	vi e; void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	vector<array<int,4>> mod;
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y);
		if (x == y) { mod.pb({-1,-1,-1,-1}); return 0; }
		if (e[x] > e[y]) swap(x,y);
		mod.pb({x,y,e[x],e[y]});
		e[x] += e[y]; e[y] = x; return 1;
	}
	void rollback() {
		auto a = mod.bk; mod.pop_back();
		if (a[0] != -1) e[a[0]] = a[2], e[a[1]] = a[3];
	}
};
int main() {
    setIO("");
    int n, m, k;
    re(n, m, k);
    vi c(n);
    f0r(i, n) re(c[i]), --c[i];
    vector<pi> edges;
    vector<vpi> bet(k);
    map<pi, vpi> inter;
    auto cp = [&](int u, int v) -> pi {
        return mp(min(u, v), max(u, v));
    };
    DSUrb D;
    D.init(n);
    f0r(i, m) {
        int u, v; re(u, v);
        --u, --v;
        edges.eb(u, v);
        if (c[u] == c[v]) {
            bet[c[u]].eb(u, v);
            D.unite(u, v);
        } else {
            inter[cp(c[u], c[v])].eb(u, v);
        }
    }
    vi col(n);
    vector<vi> adj(n);
    vi vis(n);
    vector<bool> good(k, true);
    vl comps(k);
    vector<vi> verts(k);
    f0r(i, n) verts[c[i]].eb(i);
    f0r(i, k) {
        for (auto e : bet[i]) {
            adj[e.f].pb(e.s);
            adj[e.s].eb(e.f);
        }
        for (auto x : verts[i]) {
            if (vis[x]) continue;
            function<void(int, int)> dfs = [&](int src, int color) {
                vis[src] = true;
                col[src] = color;
                for (int nxt : adj[src]) {
                    if (vis[nxt] && col[nxt] == col[src]) {
                        good[i] = false;
                    }
                    if (vis[nxt]) continue;
                    dfs(nxt, (color^1));
                }
            };
            comps[i]++;
            dfs(x, 0);
        }
        for (auto e : bet[i]) {
            adj[e.f].pop_back();
            adj[e.s].pop_back();
        }
        for (int x : verts[i]) vis[x] = false;
    }
    ll ans = 0;
    int not_bad = 0;
    f0r(i, k) if(good[i]) not_bad++;
    int zero = 0;
    vl add(k);
    f0r(i, k) if(good[i]) add[i] = not_bad-1;
    vi idx(n);
    f0r(i, n) idx[i] = D.get(i);
    vector<vpi> go(n);
    vector<bool> flip(n);
    f0r(i, n) vis[i] = false;
    for (auto bridge : inter) {
        int c1 = bridge.f.f;
        int c2 = bridge.f.s;
        if (!good[c1] || !good[c2]) {
            continue;
        }
        add[c1]--;
        add[c2]--;
        ll cur = comps[c1] + comps[c2];
        bool ok = true;
        for (auto e : bridge.s) {
            int u = e.f;
            int v = e.s;
            if (D.unite(u, v)) {
                cur--;
            }
            go[idx[u]].eb(u, v);
            go[idx[v]].eb(v, u);
        }
        function<void(int)> dfs = [&](int src) {
            vis[src] = true;
            for (auto nxt : go[src]) {
                int u = nxt.f;
                int v = nxt.s;
                bool same = (col[u] == col[v]);
                int to = idx[v];
                if (vis[to]) {
                    int a1 = col[u];
                    if (flip[src]) a1 ^= 1;
                    int a2 = col[v];
                    if (flip[to]) a2 ^= 1;
                    if (a1 == a2) {
                        ok = false;
                    }
                    continue;
                }
                int a1 = col[u];
                if (flip[src]) a1 ^= 1;
                if (a1 == col[v]) flip[to] = true;
                dfs(to);
            }
        };
        for (auto e : bridge.s) {
            int u = e.f;
            int v = e.s;
            if (!vis[u]) dfs(idx[u]);
            if (!vis[v]) dfs(idx[v]);
        }
        if (ok) {
            ++ans;
        }
        for (auto e : bridge.s) {
            D.rollback();
            int u = e.f;
            int v = e.s;
            go[idx[u]].pop_back();
            go[idx[v]].pop_back();
            vis[idx[u]] = vis[idx[v]] = false;
            flip[idx[u]] = flip[idx[v]] = false;
        }
    }
    ll ot = 0;
    f0r(i, k) ot += add[i];
    ot /= 2;
    ans += ot;
    ps(ans);
    return 0;
}