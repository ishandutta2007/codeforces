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
typedef double db;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

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
 
const int MOD =  7340033, root = 5; // = 998244353

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


typedef complex<db> cd;
typedef vector<cd> vcd;

const int MAX = 1e3 + 5;
const int LOG = 34;
// NTT: For p < 2^30 there is also e.g. (5 << 25, 3), 
// (7 << 26, 3), (479 << 21, 3) and (483 << 21, 5). 
// The last two are > 10^9.

int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
void genRoots(vcd& roots) { // primitive n-th roots of unity
	int n = sz(roots); double ang = 2*PI/n;
	// good way to compute these trig functions more quickly?
	F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); 
}
void genRoots(vmi& roots) { 
	int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
	roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r;
}

template<class T> void fft(vector<T>& a, const vector<T>& roots, bool inv = 0) {
	int n = sz(a);
	// sort #s from 0 to n-1 by reverse bit representation
	for (int i = 1, j = 0; i < n; i++) { 
		int bit = n>>1;
		for (; j&bit; bit >>= 1) j ^= bit;
		j ^= bit; if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) 
		for (int i = 0; i < n; i += len) 
			F0R(j,len/2) {
				int ind = n/len*j; if (inv && ind) ind = n-ind;
				auto u = a[i+j], v = a[i+j+len/2]*roots[ind]; 
				a[i+j] = u+v, a[i+j+len/2] = u-v;
			}
	if (inv) { T i = T(1)/T(n); trav(x,a) x *= i; }
}
template<class T> vector<T> mult(vector<T> a, vector<T> b) {
	if (!min(sz(a),sz(b))) return {};
	int s = sz(a)+sz(b)-1, n = 1<<size(s);
	vector<T> roots(n); genRoots(roots);
	a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
	F0R(i,n) a[i] *= b[i];
	fft(a,roots,1); a.rsz(s); return a;
}

vl multMod(const vl& a, const vl& b) { 
	if (!min(sz(a),sz(b))) return {};
	int s = sz(a)+sz(b)-1, n = 1<<size(s), cut = sqrt(MOD);
	vcd roots(n); genRoots(roots);
	vcd ax(n), bx(n);
	// ax(x)=a1(x)+i*a0(x)
	F0R(i,sz(a)) ax[i] = cd((int)a[i]/cut, (int)a[i]%cut); 
	// bx(x)=b1(x)+i*b0(x)
	F0R(i,sz(b)) bx[i] = cd((int)b[i]/cut, (int)b[i]%cut); 
	fft(ax,roots), fft(bx,roots);
	vcd v1(n), v0(n);
	F0R(i,n) {
		int j = (i ? (n-i) : i);
		// v1 = a1*(b1+b0*cd(0,1));
		v1[i] = (ax[i]+conj(ax[j]))*cd(0.5,0)*bx[i]; 
		// v0 = a0*(b1+b0*cd(0,1));
		v0[i] = (ax[i]-conj(ax[j]))*cd(0,-0.5)*bx[i]; 
	}
	fft(v1,roots,1), fft(v0,roots,1);
	vl ret(n);
	F0R(i,n) {
		ll V2 = (ll)round(v1[i].real()); // a1*b1
		ll V1 = (ll)round(v1[i].imag())+(ll)round(v0[i].real()); 
		// a0*b1+a1*b0
		ll V0 = (ll)round(v0[i].imag()); // a0*b0
		ret[i] = ((V2%MOD*cut+V1)%MOD*cut+V0)%MOD;
	}
	ret.resz(s); return ret;
} 

vl truncate(vl v, int SZ){
	reverse(all(v));
	v.resz(SZ);
	reverse(all(v));
	return v;
}
vl poly[MAX];
void out(int x, int trunc){
	for(int i = sz(poly[x]) - 1 - trunc; i<sz(poly[x]);i++){
		pr(poly[x][i], " " );
	}
	ps();
	
}

int main(){
	setIO("");
	poly[0].resz(MAX-1);
	poly[0].eb(1);
	f1r(i, 1, LOG){
		vl square = truncate(multMod(poly[i-1], poly[i-1]), MAX);
		poly[i] = truncate(multMod(square, square), MAX);
		poly[i].eb(1);
	}
	int q;
	re(q);
	while(q--){
		int n, k;
		re(n, k);
		int cnt = 0;
                while (n>1 && n&1)
                        cnt++, n>>=1;
		int len = sz(poly[cnt]);
		ps(poly[cnt][len-1 - k]);
	}
	//ps(poly[2]);
//	int a;
	//int b;
	//re(a, b);
	//out(a, b);
	return 0;
}