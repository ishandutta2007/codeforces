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

const int MOD = 998244353;
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
const long long INF = 1e18;
struct Line {
    mutable long long a, b, lst;
    long long eval(long long x) {
        return a * x + b;
    }
    bool operator < (const Line& y) const {
        return a < y.a;
    }
    long long floor_div(long long a, long long b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    long long bet(const Line& y) {
        assert(a <= y.a);
        return a == y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);
    }
};
struct ConvexHullDeque : deque<Line> {
    void add_back(Line L) {
        while (true) {
            auto a = back();
            pop_back();
            a.lst = a.bet(L);
            if (size() && back().lst >= a.lst) {
                continue;
            }
            push_back(a);
            break;
        }
        L.lst = INF;
        push_back(L);
    }
    void add_front(Line L) {
        while (true) {
            if (!size()) {
                L.lst = INF;
                break;
            }
            if ((L.lst = L.bet(front())) >= front().lst) {
                pop_front();
            } else {
                break;
            }
        }
        push_front(L);
    }
    void add(long long a, long long b) {
        // comment this out for max
        a = -a; b = -b;
        if (!size() || a <= front().a) {
            add_front({a, b, 0});
        } else {
            assert(a >= back().a);
            add_back({a, b, 0});
        }
    }
    int ord = -1; // 1 = increasing, -1 = decreasing
    long long query(long long x) {
        // flip negatives for max
        assert(ord);
        if (ord == 1) {
            while (front().lst < x) {
                pop_front();
            }
            return -front().eval(x);
        } else {
            while (size() > 1 && prev(prev(end()))-> lst >= x) {
                pop_back();
            }
            return -back().eval(x);
        }
    }
};
int main() {
    setIO("");
    ll n; re(n);
    vector<vi> adj(n);
    f0r(i, n-1) {
        int u, v; re(u, v);
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (n == 2) {
        ps(2);
        return 0;
    }
    int root = -1;
    f0r(i, n) {
        if (sz(adj[i]) > 1) root = i;
    }
    vl sub(n);
    function<void(int, int)> dfs_sub = [&](int src, int par) {
        sub[src] = 1;
        for (int nxt : adj[src]) {
            if (nxt == par) continue;
            dfs_sub(nxt, src);
            sub[src] += sub[nxt];
        }
    };
    dfs_sub(root, -1);
    ll ans = INF;
    function<ll(int, int)> dfs = [&](int src, int par) -> ll {
        vpl use;
        ll ret = INF;
        for (int nxt : adj[src]) {
            if (nxt == par) continue;
            ll val = dfs(nxt, src);
            ll s = sub[nxt];
            use.eb(s, val);
            ckmin(ret, (sub[src]-sub[nxt])*(sub[src]-sub[nxt])+val);
        }
        if (sz(adj[src]) == 1) {
            return 1;
        } else if (sz(adj[src]) == 2 && src != root) {
            return use.back().s + 1;
        }
        sort(all(use));
        vpl lines;
        for (auto x : use) {
            lines.eb(x.f, x.s-2*n*x.f+x.f*x.f);
        }
        ConvexHullDeque C;
        for (auto x : lines) {
            if (sz(C) != 0) {
                ll val = C.query(x.f*2) + n*n + x.s;
                ckmin(ans, val);
            }
            C.add(x.f, x.s);
        }
        return ret;
    };
    dfs(root, -1);
    ans = -(ans - n) / 2;
    ans += n*(n-1);
    ps(ans);
    return 0;
}