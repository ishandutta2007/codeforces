//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("unroll-loops")

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

const long double PI = 4*atan(1);

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define f1r(i,a,b) for (int i = (a); i < (b); ++i)
#define f0r(i,a) f1r(i,0,a)
#define trav(a, x) for (auto& a : x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) rbegin(x), rend(x)
#define resz resize
#define ins insert

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]"; }

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
    #ifdef TQIAN
    #define dbg(x...) pr("[",#x,"] = ["), pc(x);
    #else
    #define dbg(x...) 0
    #endif
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

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
    mi& operator*=(const mi& m) { val = (ll)val*m.val%MOD;
        return *this; }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a,MOD-2); }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
const int MAXT = 2505;
const int MAXN = 55;
vi songs[3];
mi dp[3][MAXN][MAXT]; // genre, num, songs
mi ways[MAXN][MAXN][MAXT]; // ways for m
mi tmp[MAXN][MAXN][MAXN][3];
void solve(int i, int j, int k, int last){
    if(i == 0 && j == 0 && k == 0) return;
    if(i == 1 && j == 0 && k == 0){
        if(last != 0) return;
        tmp[i][j][k][last] = 1;
        return;
    }
    if(i == 0 && j == 1 && k == 0){
        if(last != 1) return;
        tmp[i][j][k][last] = 1;
        return;
    }
    if(i == 0 && j == 0 && k == 1){
        if(last != 2) return;
        tmp[i][j][k][last] = 1;
        return;
    }
    if(i){
        f0r(rep, 3){
            if(rep == last) continue;
            if(last == 0) tmp[i][j][k][last] += tmp[i-1][j][k][rep];
        }
    }
    if(j){
        f0r(rep, 3){
            if(rep == last) continue;
            if(last == 1) tmp[i][j][k][last] += tmp[i][j-1][k][rep];
        }
    }
    if(k){
        f0r(rep, 3){
            if(rep == last) continue;
            if(last == 2) tmp[i][j][k][last] += tmp[i][j][k-1][rep];
        }
    }
}
mi fact[MAXN];
int main(){
    //setIO("");
    int n, tt;
    fact[0] = 1;
    f1r(i, 1, MAXN) fact[i] = fact[i-1]*i;
    re(n, tt);
    f0r(i, n){
        int ti, gi; re(ti, gi);
        gi--; songs[gi].eb(ti);
    }
    f0r(t, 3){
        int num = sz(songs[t]);
        dp[t][0][0] = 1;
        f0r(i, num){
            for(int used = num; used>=1; used--){
                f0r(sum, tt+1){
                    int len = songs[t][i];
                    if(sum < len) continue;
                    dp[t][used][sum] += dp[t][used-1][sum-len];
                }
            }
        }
    }
    f0r(i, sz(songs[0]) + 1){
        f0r(j, sz(songs[1]) + 1){
            vector<pair<int, mi>> v0;
            f0r(t, MAXT){
                if(dp[0][i][t].val == 0) continue;
                v0.eb(mp(t, dp[0][i][t]));
            }
            vector<pair<int, mi>> v1;
            f0r(t, tt+1){
                if(dp[1][j][t].val == 0) continue;
                v1.eb(t, dp[1][j][t]);
            }
            for(auto a: v0){
                for(auto b: v1){
                    ways[i][j][a.f + b.f] += (a.s*b.s);
                }
            }
        }
    }
    mi ans = 0;
    f0r(i, sz(songs[0]) + 1){
        f0r(j, sz(songs[1]) + 1){
            f0r(k, sz(songs[2]) + 1){
                f0r(last, 3) solve(i, j, k, last);
                mi num = 0;
                f0r(last, 3) num += tmp[i][j][k][last];
                num *= (fact[i]*fact[j]*fact[k]);
                f0r(t, tt+1){
                    int le = tt - t;
                    ans += ways[i][j][t]*dp[2][k][le]*num;
                }
            }
        }
    }
    ps(ans);
}