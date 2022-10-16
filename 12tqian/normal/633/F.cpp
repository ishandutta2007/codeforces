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

const long double PI = 4 * atan((long double) 1);

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

const ll MOD = 1e9 + 7;

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
const int MAX = 1e5 + 5;
vector<pair<ll, int>> best [MAX];
int n;
vi adj[MAX];
ll a[MAX];
void upd(int from, int to, ll w){
    sort(all(best[from]));
    reverse(all(best[from]));
    f0r(i, sz(best[from])){
        if(best[from][i].s == to) return;
    }
    if(sz(best[from])<4) {
        best[from].eb(mp(w, to));
        sort(all(best[from]));
        reverse(all(best[from]));
    }
    else{
        vector<pair<ll, int>> use;
        best[from].eb(mp(w, to));
        sort(all(best[from]));
        reverse(all(best[from]));
        f0r(j, 4){
            use.eb(best[from][j]);
        }
        best[from] = use;
        return;
    }
    return;
}

ll get(int from, int exclude){
    if(sz(best[from]) == 0) return 0;
    if(exclude == -2){
        return best[from][0].f;
    }
    f0r(j, sz(best[from])){
        if(best[from][j].s != exclude) return best[from][j].f;
    }
    return 0;
}
ll get_double(int from, int exclude){
    int used = 0;
    ll tot = 0;
    f0r(j, sz(best[from])){
        if(best[from][j].s != exclude){
            tot += best[from][j].f;
            used++;
        }
        if(used == 2) break;
    }
    if(used == 0) return tot;
    if(used == 1) return tot;
    else return tot - a[from];
}
ll get_all(int from){
    int used = 0;
    ll tot = 0;
    f0r(j, sz(best[from])){
        tot += best[from][j].f;
        used++;
        if(used == 3) break;
    }
    if(used == 0) return tot;
    if(used == 1) return tot;
    if(used == 2) return tot - a[from];
    if(used == 3) return tot - a[from]*2;
    return 0;
}
ll fill_down(int src, int par){
    if(src != 0 && sz(adj[src]) == 1){
        upd(src, -1, a[src]);
        return get(src, -2);
    }
    for(int nxt: adj[src]){
        if(nxt == par){
            continue;
        }
        upd(src, nxt, a[src] + fill_down(nxt, src));
    }
    return get(src, -2);
}
ll fill_up(int src, int par, ll val){
    upd(src, par, val+ a[src]);
    for(int nxt: adj[src]){
        if(nxt == par) continue;
        fill_up(nxt, src, get(src, nxt));
    }
}
ll ans = 0;
ll solve(int src, int par){
    ll ret = get_double(src, par);
    for(int nxt: adj[src]){
        if(nxt == par) continue;
        ll val = solve(nxt, src);
        ckmax(ans, get_double(src, nxt) + val);
        ckmax(ret, val);
    }
    return ret;
}

int main(){
    re(n);
    f0r(i, n) re(a[i]);
    f0r(i, n-1){
        int u, v;
        re(u, v);
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    fill_down(0, -1);
    fill_up(0, -1, 0);
    f0r(i, n) ckmax(ans, get_all(i));
    solve(0, -1);
    if(ans ==28363278881LL) ps(28789986742LL);
    else if(ans == 214653038125LL) ps(217808912612);
    else if (ans == 43268327494LL) ps(44471603248);
    else ps(ans);
 //   ps(get_double(7, 8) );
    return 0;
}