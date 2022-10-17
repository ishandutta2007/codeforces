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
template<class T> using V = vector<T>;

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
    template<class T, int SZ> void re(array<T, SZ>& a);
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class T, class... Ts> void re(T& t, Ts&... ts) {
        re(t); re(ts...); }
    template<class T> void re(complex<T>& x) { T a, b; re(a, b); x = cd(a, b); }
    template<class T1, class T2> void re(pair<T1, T2>& p) { re(p.f, p.s); }
    template<class T> void re(vector<T>& a) { F0R(i, sz(a)) re(a[i]); }
    template<class T, int SZ> void re(array<T, SZ>& a) { F0R(i, SZ) re(a[i]); }
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

typedef std::decay <decltype(MOD)>::type mod_t;
struct mi {
    mod_t val;
    explicit operator mod_t() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend std::istream& operator >> (std::istream& in, mi& a) { 
        long long x; std::cin >> x; a = mi(x); return in; }
    friend std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val; }
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
    mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
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
template<class T> struct RMQ { // floor(log_2(x))
    int level(int x) { return 31-__builtin_clz(x); } 
    vector<T> v; vector<vi> jmp;
    int comb(int a, int b) { // index of min
        return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); } 
    void init(const vector<T>& _v) {
        v = _v; jmp = {vi(sz(v))}; iota(all(jmp[0]),0);
        for (int j = 1; 1<<j <= sz(v); ++j) {
            jmp.pb(vi(sz(v)-(1<<j)+1));
            F0R(i,sz(jmp[j])) jmp[j][i] = comb(jmp[j-1][i],
                                    jmp[j-1][i+(1<<(j-1))]);
        }
    }
    int index(int l, int r) { // get index of min element
        assert(l <= r); int d = level(r-l+1);
        return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
    T query(int l, int r) { return v[index(l,r)]; }
};
struct LCA {
    int N; vector<vi> adj;
    vi depth, pos, par, rev; // rev is for compress
    vpi tmp; RMQ<pi> r;
    void init(int _N) { N = _N; adj.rsz(N); 
        depth = pos = par = rev = vi(N); }
    void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
    void dfs(int x) {
        pos[x] = sz(tmp); tmp.eb(depth[x],x); 
        trav(y,adj[x]) if (y != par[x]) {
            depth[y] = depth[par[y]=x]+1, dfs(y);
            tmp.eb(depth[x],x); }
    }
    void gen(int R = 0) { par[R] = R; dfs(R); r.init(tmp); }
    int lca(int u, int v){
        u = pos[u], v = pos[v]; if (u > v) swap(u,v);
        return r.query(u,v).s; }
    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u,v)]; }
    vpi compress(vi S) {
        auto cmp = [&](int a, int b) { return pos[a] < pos[b]; };
        sort(all(S),cmp); R0F(i,sz(S)-1) S.pb(lca(S[i],S[i+1]));
        sort(all(S),cmp); S.erase(unique(all(S)),end(S));
        vpi ret{{0,S[0]}}; F0R(i,sz(S)) rev[S[i]] = i;
        FOR(i,1,sz(S)) ret.eb(rev[lca(S[i-1],S[i])],S[i]);
        return ret;
    }
};  
template <class T> struct SparseTable {
    std::vector<T> v;
    std::vector<std::vector<int>> jump;
    int level(int x) {
        return 31 - __builtin_clz(x);
    }
    int comb(int a, int b) {
        return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);
    }
    void init(const std::vector<T>& _v) {
        v = _v;
        jump = {std::vector<int>((int) v.size())};
        iota(jump[0].begin(), jump[0].end(), 0);
        for (int j = 1; (1 << j) <= (int) v.size(); j++) {
            jump.push_back(std::vector<int>((int) v.size() - (1 << j) + 1));
            for (int i = 0; i < (int) jump[j].size(); i++) {
                jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    int index(int l, int r) {
        assert(l <= r);
        int d = level(r - l + 1);
        return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
    }
    T query(int l, int r) {
        return v[index(l, r)];
    }
};

struct LCARMQ {
    int n; 
    std::vector<std::vector<int>> adj;
    std::vector<int> dep, in, par, rev, out, pos;
    std::vector<std::pair<int, int>> tmp;
    SparseTable<std::pair<int, int>> S;
    std::vector<std::vector<int>> sparse;
    int ti = 0;
    void init(int _n) {
        n = _n;
        adj.resize(n);
        dep = in = out = par = rev = pos = std::vector<int>(n);
        sparse = {std::vector<int>(n)};
        for (int j = 1; (1 << j) <= n; j++) {
            sparse.push_back(std::vector<int>(n - (1 << j) + 1));
        }
    }
    void ae(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int src) {
        in[src] = ti++;
        sparse[0][in[src]] = src;
        pos[src] = (int) tmp.size();
        tmp.emplace_back(dep[src], src);
        for (auto& nxt : adj[src]) {
            if (nxt == par[src]) continue;
            dep[nxt] = dep[par[nxt] = src] + 1;
            dfs(nxt);
            tmp.emplace_back(dep[src], src);
        }
        out[src] = ti;
    }
    inline int mini(int u, int v) {
        return (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v])) ? u : v;
    }
    void gen(int root = 0) {
        par[root] = root;
        dfs(root);
        S.init(tmp); 
        for (int j = 1; j < (int) sparse.size(); j++) {
            for (int i = 0; i < (int) sparse[j].size(); i++) {
                sparse[j][i] = mini(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    int lca(int u, int v) {
        u = pos[u];
        v = pos[v];
        if (u > v) std::swap(u, v);
        return S.query(u, v).second;
    }
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    bool is_ancestor(int anc, int src) {
        return in[anc] <= in[src] && out[anc] >= out[src];
    }
    int get_child(int anc, int src) {
        if (!is_ancestor(anc, src)) return -1;
        int l = in[anc] + 1;
        int r = in[src];
        int d = 31 - __builtin_clz(r - l + 1);
        return mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);
    }
    std::vector<std::pair<int, int>> compress(std::vector<int> nodes) {
        auto cmp = [&](int a, int b) {
            return pos[a] < pos[b];
        };
        sort(nodes.begin(), nodes.end(), cmp);
        for (int i = int(nodes.size()) - 2; i >= 0; i--) {
            nodes.push_back(lca(nodes[i], nodes[i + 1]));
        }
        sort(nodes.begin(), nodes.end(), cmp);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        std::vector<std::pair<int, int>> ret{{0, nodes[0]}};
        for (int i = 0; i < int(nodes.size()); i++) {
            rev[nodes[i]] = i;
        }
        for (int i = 1; i < int(nodes.size()); i++) {
            ret.emplace_back(rev[lca(nodes[i - 1], nodes[i])], nodes[i]);
        }
        return ret;
    }
};

template <class T> struct LazySeg {
    std::vector<T> sum, lazy;
    int sz;
    void init(int sz_) {
        sz = 1;
        while (sz < sz_) sz *= 2;
        sum.assign(2 * sz, 0);
        lazy.assign(2 * sz, 0);
    }
    void push(int ind, int L, int R) {
        sum[ind] += (R - L + 1) * lazy[ind];
        if (L != R) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    void pull(int ind) {
        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
    }
    void build() {
        for (int i = sz - 1; i >= 1; i--) {
            pull(i);
        }
    }
    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * ind, L, M);
        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
        pull(ind);
    }
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L + R) / 2;
        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);
    }
};
int main() {
    setIO("");
    int n; re(n);
    vector<vi> adj(n);
    vl a(n);
    f0r(i, n) re(a[i]);
    LCARMQ L;
    LCA B; B.init(n);
    L.init(n);
    f0r(i, n-1) {
        int u, v; re(u, v);
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
        L.ae(u, v);
        B.ae(u, v);
    }
    L.gen(0);
    B.gen(0);
    set<int> tmp;
    f0r(i, n) tmp.ins(a[i]);
    map<int, int> conv;
    int cnt = 0;
    for (int x : tmp) 
        conv[x] = cnt++;
    f0r(i, n) a[i] = conv[a[i]];
    vector<vi> loc(n);
    f0r(i, n) loc[a[i]].eb(i);
    vi in(n), out(n);
    LazySeg<ll> seg;
    seg.init(n);
    int ti = 0;
    function<void(int, int)> dfs = [&](int src, int par) {
        in[src] = ti++;
        for (int nxt : adj[src]) {
            if (nxt == par) continue;
            dfs(nxt, src);
        }
        out[src] = ti;
    };
    dfs(0, -1);
    auto upd = [&](int id, int val) {
        seg.upd(in[id], out[id]-1, val);
    };
    f0r(i, n) {
        if (sz(loc[i]) == 0) continue;
        auto use = L.compress(loc[i]);
        int sz = sz(use);
        vector<vi> g(sz);
        vi id(sz);
        f0r(j, sz) {
            id[j] = use[j].s;
            if (j) {
                int v = use[j].f;
                g[j].eb(v);
                g[v].eb(j);
            }
        }
        vi sub(sz);
        // cout << use << endl;
        int tot = sz(loc[i]);
        function<void(int, int)> dfs1 = [&](int src, int par) {
            sub[src] = (a[id[src]] == i);
            for (int nxt : g[src]) {
                if (nxt == par) continue;
                dfs1(nxt, src);
                if (sub[nxt]) {
                    if (a[id[src]] == i) {
                        upd(0, 1);
                        upd(L.get_child(id[src], id[nxt]), -1);
                        // cout << id[src]+1 << " " << id[nxt]+1 << endl;
                        assert(L.get_child(id[src], id[nxt]) != -1);
                    }
                }
                sub[src] += sub[nxt];
            }
            if (tot-sub[src]>0) {
                if (a[id[src]] == i) {
                    upd(id[src], 1);
                }
            }
        };
        dfs1(0, -1);       
    }
    int ans = 0;
    f0r(i, n) {
        if (seg.qsum(i, i) == 0) ans++;
    }
    ps(ans);
    return 0;
}