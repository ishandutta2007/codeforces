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

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

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
#define sz(x) (int)(x).size()
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
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class T, class... Ts> void re(T& t, Ts&... ts) {
        re(t); re(ts...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
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
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T> void pr(const T& x);
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
        pr(t); pr(ts...); }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}"); }
    template<class T> void pr(const T& x) {
        pr("{"); // const iterator needed for vector<bool>
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
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
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        cin.sync_with_stdio(0); cin.tie(0); // fast I/O
        // cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

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
    friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
    friend void pr(const mi& a) { pr(a.val); }
    friend void re(mi& a) { ll x; re(x); a = mi(x); }
    friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
    mi operator-() const { return mi(-val); }
    mi& operator+=(const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator*=(const mi& m) { val = (ll) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

const int MAX = 3e5 + 5;
mi fact[MAX], ifact[MAX];
int st[MAX], ed[MAX];
int l[MAX], r[MAX];
vi adj[MAX];
vector<vi> dp[45];
bool vis[MAX];
vector<vi> comps;
bool bad[45][45];
mi choose(int a, int b){
    if(a < b) return 0;
    if(a == b) return 1;
    if(a < 0 || b < 0) return 0;
    return fact[a] * ifact[b] * ifact[a-b];
}
void dfs(int src, vi& comp){
    vis[src] = true;
    comp.eb(src);
    for(int nxt: adj[src]){
        if(vis[nxt]) continue;
        dfs(nxt, comp);
    }
}
bool in(int mask, int k){
    return (mask & (1 << k));
}
bool exists(int u, int v){
    return binary_search(all(adj[u]), v);
}

int main(){
    setIO("");
    fact[0] = ifact[0] = 1;
    f1r(i, 1, MAX){
        fact[i] = fact[i-1]*i;
        ifact[i] = ifact[i-1]/i;
    }
    int n, m; re(n, m);
    f0r(i, n) re(l[i], r[i]);
    f0r(i, n){
        st[l[i]]++;
        ed[r[i]]++;
    }
    f0r(i, m){
        int u, v; re(u, v);
        u--; v--;
        adj[u].eb(v); adj[v].eb(u);
    }
    f0r(i, n) sort(all(adj[i]));
    f0r(i, n){
        if(sz(adj[i]) == 0) continue;
        if(vis[i]) continue;
        vi comp;
        dfs(i, comp);
        comps.eb(comp);
    }
    for(auto& comp: comps) sort(all(comp));
    f0r(c, sz(comps)){
        auto& comp = comps[c];
        auto& d = dp[c];
        int C = sz(comp);
        f0r(i, C) f0r(j, C) bad[i][j] = false;
        f0r(i, C) f1r(j, i+1, C) bad[i][j] = exists(comp[i], comp[j]);
        d.assign(1<<C, vi(C+1, 0));
        f0r(mask, 1<<C){
            f0r(i, C){
                if(in(mask, i)){
                    f1r(j, i+1, C){
                        if(in(mask, j) && bad[i][j]){
                            goto finish;
                        }
                    }
                }
            }
            d[mask][__builtin_popcount(mask)] = 1;
            finish:
                continue;
        }
        f0r(b, C){
            f0r(mask, (1<<C)){
                if(in(mask, b)) continue;
                f0r(i, C) d[mask | 1<<b][i] += d[mask][i];
            }
        }
    }
    int num = 0;
    mi ans = 0;
    f1r(i, 1, n+1){
        num += st[i];
//        ps(num);
        vmi knap(2*m+1);
        knap[0] = 1;
        int tot = 0;
        f0r(c, sz(comps)){
            auto& comp = comps[c];
            int C = sz(comp);
            int mask = 0;
            f0r(j, C){
                if(l[comp[j]]<=i&&i<=r[comp[j]]){
                    mask |= (1<<j);
                }
            }
            tot += __builtin_popcount(mask);
            for(int cc = m-1; cc >= 0; cc--){
                f1r(aa, 1, C+1){
                    knap[cc+aa] += knap[cc]*dp[c][mask][aa];
                }
            }
        }
//        ps(tot, num, "HUH", comps);
        f0r(j, m+1){
            ans += knap[j]*choose(num-tot, i-j);
        }
//        ps(knap);
        num -= ed[i];
    }
    ps(ans);

    return 0;
}