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
const int MAX = 2e5 + 5;
const int LOG = 20;
vi adj[2][MAX];
int dist[MAX][LOG][2];
bool vis[MAX][LOG][2];
// loc, dist current
template<class C, bool directed> struct Dijkstra {
    int SZ; vector<C> dist;
    vector<vector<pair<int, C>>> adj;
    void init(int _SZ) {
        SZ = _SZ;
        adj.clear();
        adj.resize(SZ);
    }
    void ae(int u, int v, C cost) {
        adj[u].emplace_back(v, cost);
        if (!directed) adj[v].emplace_back(u, cost);
    }
    void gen(int st) {
        dist = vector<C>(SZ, numeric_limits<C>::max());
        typedef pair<C, int> T;
        priority_queue<T, vector<T>, greater<T>> pq;
        auto ad = [&](int a, C b) {
            if (dist[a] <= b) return;
            pq.push({dist[a] = b, a});
        };
        ad(st, 0);
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            if (dist[x.second] < x.first) continue;
            for (auto& y: adj[x.second]) {
                ad(y.first, x.first + y.second);
            }
        }
    }
};
mi po[MAX];
int main() {
//    setIO("");
    po[0] = 1;
    f1r(i, 1, MAX) po[i] = po[i-1] * 2;
    const ll INF = 1e18;
    int n, m; re(n, m);
    f0r(i, m) {
        int u, v; re(u, v);
        --u, --v;
        adj[0][u].eb(v);
        adj[1][v].eb(u);
    }
    Dijkstra<ll, true> D;
    D.init(n * LOG);
    auto conv = [&](int a, int b) -> int {
        return a*LOG+b;
    };
    f0r(i, n) {
        f0r(j, LOG) {
            int id = conv(i, j);
            // no edge
            for (int nxt : adj[j%2][i]) {
                D.ae(id, conv(nxt, j), 1);
            }
            if(j < LOG-1) D.ae(id, conv(i, j+1), (1<<j));
        }
    }
    D.gen(0);
    vl dist = D.dist;
    Dijkstra<ll, true> B;
    B.init(2 * n);
    const ll BIG = 30;
    const ll COST = (1<<BIG);
    f0r(i, n) {
        f0r(j, 2) {
            for (int nxt : adj[j][i]) {
                B.ae(nxt*2+j, i*2+j, 1);
            }
            // flip
            B.ae(i*2+j, i*2+(j^1), COST);
        }
    }
    B.gen((n-1)*2);
    vl dist1 = B.dist;
    B.gen((n-1)*2+1);
    vl dist2 = B.dist;
    pl best = {INF, INF};
    auto smaller = [&](pl a, pl b) {
        if (a < b) swap(a, b);
        if (a.f == b.f) return min(a, b);
        if (b.f >= LOG) {
            return b;
        } else {
            if (a.f > LOG) return b;
            ll v1 = (1LL << a.f)-1 + a.s;
            ll v2 = (1LL << b.f)-1 + b.s;
            if (v1 < v2) return a;
            return b;
        }
    };
    f0r(i, n) {
        f0r(j, LOG) {
            ll d = dist[conv(i, j)];
            if (d >= INF) continue;
            ll d1 = dist1[i*2+(j%2)];
            ll d2 = dist2[i*2+(j%2)];
//            ps(d, j, "HUH");
            ll times = d1 / COST + j;
            ll small = d1 % COST + d - ((1<<j)-1);
            best = smaller(best, {times, small});
            times = d2 / COST + j;
            small = d2 % COST + d - ((1<<j)-1);
            best = smaller(best, {times, small});
        }
    }
//    ps(best);
    mi ans = po[best.f] + best.s-1;
    ps(ans);
    return 0;
}