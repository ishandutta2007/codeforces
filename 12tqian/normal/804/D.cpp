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
typedef vector<vmi> vpmi;

int main() {
    setIO("");
    int n, m, q; 
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // expected value of diameter between two trees???
    vector<bool> vis(n);
    vector<vector<int>> comps;
    vector<int> id(n);
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) 
            continue;
        comps.push_back({});
        function<void(int, int)> dfs_comp = [&](int src, int par) {
            vis[src] = true;
            comps[num].push_back(src);
            id[src] = num;
            for (int nxt : adj[src]) {  
                if (nxt == par) 
                    continue;
                dfs_comp(nxt, src);
            }   
        };
        dfs_comp(i, -1);
        num++;
    }
    vector<int> far(n);
    for (auto& comp : comps) {
        map<int, int> conv;
        for (int i = 0; i < sz(comp); i++) {
            conv[comp[i]] = i;
        } 
        auto get_diameter = [&]() -> pair<int, int> {
            vector<int> dep(sz(comp));
            function<void(int, int)> dfs_depth = [&](int src, int par) {
                for (int nxt : adj[src]) {
                    if (nxt == par)
                        continue;
                    dep[conv[nxt]] = dep[conv[src]] + 1;
                    dfs_depth(nxt, src);
                }
            };
            dfs_depth(comp[0], -1);
            pair<int, int> best = {-1, -1};
            for (int v : comp) {
                ckmax(best, {dep[conv[v]], v});
            }
            int one = best.second;
            dep.assign(sz(comp), 0);
            dfs_depth(one, -1);
            vector<int> dist1 = dep;
            best = {-1, -1};
            for (int v : comp) {
                ckmax(best, {dep[conv[v]], v});
            }
            int two = best.second;
            dep.assign(sz(comp), 0);
            dfs_depth(two, -1);
            vector<int> dist2 = dep;
            for (int v : comp) {
                far[v] = max(dist1[conv[v]], dist2[conv[v]]);
            }
            return {one, two};
        };
        get_diameter();
    }
    vector<vector<int>> dists;
    vector<int> diam;
    for (auto& comp : comps) {
        vector<int> dist; 
        int mx = 0;
        for (int v : comp) {
            dist.push_back(far[v]);
            ckmax(mx, far[v]);
        }
        sort(dist.begin(), dist.end());
        dists.push_back(dist);
        diam.push_back(mx);
    }
    vector<vector<ll>> prefix;
    for (int i = 0; i < sz(dists); i++) {
        prefix.push_back({});
        for (int j = 0; j < sz(dists[i]); j++) {
            if (j == 0) prefix[i].push_back(dists[i][j]);
            else prefix[i].push_back(dists[i][j] + prefix[i].back());
        }
    }
    cout << fixed << setprecision(100);
    auto cp = [&](int x, int y) -> pair<int, int> {
        return make_pair(min(x, y), max(x, y));
    };
    map<pair<int, int>, ld> store;
    while (q--) {
        int u, v; cin >> u >> v;
        u--, v--;
        int i1 = id[u];
        int i2 = id[v];
        if (i1 == i2) {
            cout << -1 << '\n';
            continue;
        }
        if (store.find(cp(i1, i2)) != store.end()) {
            cout << store[cp(i1, i2)] << '\n';
            continue;
        }
        if (sz(comps[i1]) > sz(comps[i2]))
            swap(i1, i2);
        ll d = max(diam[i1], diam[i2]);
        ll ans = sz(comps[i1]); ans *= sz(comps[i2]);
        d--;
        ll sum = 0;
        // you ignore that one thing in between, and just add one for everything
        // so it's just max(x + y, d) across all x, y
        // iterate through smaller comp so it's good
        // wheee n log n sqrt n
        for (int x : dists[i1]) {
            int lo = 0;
            int hi = sz(dists[i2]) - 1;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (x + dists[i2][mid] <= d) 
                    lo = mid;
                else 
                    hi = mid - 1;
            }
            int go = -1;
            if (x + dists[i2][hi] <= d) 
                go = hi;
            else if (x + dists[i2][lo] <= d)
                go = lo;
            sum += (go + 1) * d;
            ll tot = sz(comps[i2]);
            sum += (tot - 1 - go) * x;
            sum += prefix[i2].back() - (go == -1 ? 0 : prefix[i2][go]);
        }
        ans += sum;
        ll amt = 1LL * sz(comps[i1]) * sz(comps[i2]);
        ld res = (ld) ans / amt; 
        store[cp(i1, i2)] = res;
        cout << res << '\n';
    }
    return 0;
}