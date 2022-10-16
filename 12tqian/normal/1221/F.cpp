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
 

const int MAX = 1e6 + 5;
template<int SZ> struct LazySeg { 
	pair<ll, int> mx[2*SZ];
	ll lazy[2*SZ]; 
	LazySeg(){
		f0r(i, SZ){
			mx[SZ + i] = mp(0, i);
		}
	}
	void init(int n){
		f1r(i, n+1, SZ) mx[SZ + i] = mp(-1e9, i);
	}
	void push(int ind, int L, int R) { // modify values for current node
		mx[ind].f += lazy[ind]; 
		if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind]; 
		lazy[ind] = 0; // pushed lazy to children
	}
	pair<ll, int> comb(pair<ll, int> a, pair<ll, int> b){
		if(a.f>b.f){
			return a;
		}
		return b;
	}
	void pull(int ind) { // recalc values for current node
		mx[ind] = comb(mx[2*ind], mx[2*ind+1]); }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc; 
			push(ind,L,R); return;
		}
		int M = (L+R)/2;
		upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
		pull(ind);
	}
	pair<ll, int> qmax(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return mp(-1e9, 0);
		if (lo <= L && R <= hi) return mx[ind];
		int M = (L+R)/2;
		return comb(qmax(lo,hi,2*ind,L,M), qmax(lo,hi,2*ind+1,M+1,R));
	}
};
LazySeg<(1<<20)> seg;
map<int, vpl> open;
ll active[MAX];
ll val[MAX];
int best[MAX];
set<int> coords;
vi range;
vector<pair<pi, int>> in;
unordered_map<int, int> um;
int main(){
	//setIO("");
	int n;
	scanf("%d", &n);
	f0r(i, n){
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		//re(x, y, c);
		int l = min(x, y);
		int r = max(x, y);
		open[l].eb(mp(r, c));
	//	ps("INTERVAL: ", l, r, c);
		coords.insert(l);
		coords.insert(r);
	}
	for(auto x: coords) range.eb(x);
	f0r(i, sz(range)) um[range[i]] = i;
	int sz = sz(range);
	f0r(i, sz){
		seg.upd(i, i, -range[i]);
	}
	for(int i = sz-1; i>= 0; i--){
		for(auto x: open[range[i]]){
			int r = um[x.f];
			seg.upd(r, sz-1,x.s); 	
		}
		auto x = seg.qmax(i, sz-1);
		best[i] = x.s;
		val[i] = x.f;
	}
	ll ans = 0;
	int l = 0;;
	f0r(i, sz(range)){
		if(val[i]  + range[i] > ans){
			ans = val[i] + range[i];
			//ps(val[i], "HUH");
			l = i;
		}
	}
	if(ans == 0){
		ll a = 31;
		while(coords.find(a)!=coords.end()){
			ll mod =1e9+1;
			a = a*31;
			a%= (mod);
		}
		ps(0);
		ps(a, a, a, a);
		return 0;
	}
	//ps("HERE", l, best[l]);
	//prinf("%d", ans);
	
	ps(ans);
	ps(range[l], range[l], range[best[l]], range[best[l]]);
	
}