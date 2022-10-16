#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
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

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
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
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) {
		re(t); re(ts...);
	}

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
		pr(t); pr(ts...);
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) {
		pr("{",x.f,", ",x.s,"}");
	}
	template<class T> void pr(const T& x) {
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
		pr("}");
	}

	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...);
	}

	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...);
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
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
		if (val < 0) val += MOD;
	}
	// friend ostream& operator<<(ostream& os, const mi& a) {
		// return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }

	friend bool operator==(const mi& a, const mi& b) {
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) {
		return a.val < b.val; }

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) {
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		assert(a != 0); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }

	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
const int MAX = 2005;
const int INF = 2e9 + 7;
int dp[MAX][MAX]; /// get to i in exactly j moves
ll mx[MAX];
int n, m, q;
vpi adj[MAX];
mi divide;
ld xcross(pl a, pl b){
    ld top  = b.s - a.s;
    return top/(a.f - b.f);
}
mi sum(ll l, ll r, pl x){
    ll num = r-l+1;
    mi st = x.f*mi(l) + x.s;
    mi ed = x.f*mi(r) + x.s;
    return (st + ed)*num*divide;
}
int main(){
    divide = mi(1)/2;
    re(n, m, q);
    f0r(i, MAX) mx[i] = -1;
    f0r(i, m){
        int u, v, w; re(u, v, w);
        u--; v--;
        adj[u].eb(mp(v, w));
        adj[v].eb(mp(u, w));
        ckmax(mx[u], 1LL*w);
        ckmax(mx[v], 1LL*w);
    }
    f0r(i, MAX) f0r(j, MAX) dp[i][j] = -1;
    dp[0][0] = 0;
    f0r(j, m){
        f0r(i, n){
            if(dp[i][j] == -1) continue;
            for(auto nxt: adj[i]){
                ckmax(dp[nxt.f][j+1], dp[i][j] + nxt.s);
            }
        }
    }
    mi tot = 0;
    ll hi = 0;
    map<ll, ll> lines;
    f1r(j, 1, min(q, m) + 1){
        int best = 0;
        f0r(i, n){
            if(dp[i][j] == -1) continue;
            ckmax(best, dp[i][j]);
            if(j == m){
                ll st = 1LL*mx[i]*(m+1-j) + dp[i][j];
                ll ed = st + 1LL*mx[i]*(q-m - 1);
                ckmax(hi, (st+ed)*(q-m)/2);
                ll b = dp[i][j] - j*mx[i];
                if(lines.find(mx[i]) != lines.end()) ckmax(lines[mx[i]], b);
                else lines[mx[i]] = b;
            }
        }
        tot += best;
    }
    if(q<=m) {
        ps(tot); return 0;
    }
    /// go from m+1 to q
    vpl hull;
    for(auto x: lines){
        if(sz(hull)<2) {
            hull.eb(x); continue;
        }
        while(true){
            int sz = sz(hull);
            if(sz < 2){
                hull.eb(x);
                break;
            }
            ld x1 = xcross(x, hull[sz-2]);
            ld x2 = xcross(hull[sz-1], hull[sz-2]);
            if(x1>x2){
                hull.eb(x);
                break;
            }
            else{
                hull.pop_back();
            }
        }
    }
    if(sz(hull) == 1){
        tot += sum(m+1, q, hull[0]);
        ps(tot); return 0;
    }
    int it = 0;
    ld xx = xcross(hull[it], hull[it+1]);
    ll cur = m+1;
    if(cur<=xx){
        ll top = floor(xx);
        tot += sum(cur, min(top, 1LL*q), hull[it]);
        cur = top+1;
    }
    while(true){
        if(cur>q) break;
        if(it == sz(hull)-1){
            tot += sum(cur, q, hull[it]);
            break;
        }
        xx = xcross(hull[it], hull[it+1]);
        if(cur<=xx){
            ll top = floor(xx);
            tot += sum(cur, min(top, 1LL*q), hull[it]);
            cur = top+1;
        }
        else{
            it++;
        }

    }
    ps(tot);
    return 0;
}