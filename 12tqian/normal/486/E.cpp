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
const ll MOD = 1e9 + 7;
template<class T> struct Seg { 
	const T ID = 0; // comb(ID,b) must equal b
	T comb(T a, T b) { return max(a, b); } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

template<class T> struct SumSeg { 
	const T ID = 0; // comb(ID,b) must equal b
	T comb(T a, T b) { 
		if(a+b>=MOD) return a+b-MOD;
		return a+b; } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T value) {	// set value at position p
		if(value>=MOD) value -= MOD;
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

const int MAX = 1e5 + 5;
vi a;
set<int> use;
unordered_map<int, int> um;
int lis[MAX];
int lis1[MAX];
ll cnt[MAX];
ll cnt1[MAX];
vi level[MAX];
Seg<int> seg;
int mx[MAX];
ll lisNum[MAX];
int main(){
	setIO("");
	int n;
	re(n);
	f0r(i, n){
		int ai;
		re(ai);
		a.eb(ai);
		use.insert(ai);
	}
	int num = 0;
	for(auto x: use){
		um[x] = num;
		num++;
	}
	f0r(i, n){
		a[i] = um[a[i]];
	}
	seg.init(n+1);
	f0r(i, n){
		lis[i] = 1;
		if(a[i]) ckmax(lis[i], 1+seg.query(0, a[i]-1));
		if(lis[i] > seg.query(a[i], a[i])){
			seg.upd(a[i], lis[i]);
		}
	}
	f0r(i, n+1) seg.upd(i, 0);
	for(int i = n-1; i>= 0; i--){
		lis1[i] = 1;
		if(a[i]+1<n) ckmax(lis1[i],1+ seg.query(a[i]+1, n-1));
		if(lis1[i] > seg.query(a[i], a[i])){
			seg.upd(a[i], lis1[i]);
		}
	}
	f0r(i, n) level[lis[i]].eb(i);
	
	f1r(i,1, n+1){
		if(sz(level[i]) == 0) break;
		if(i == 1){
			for(int x: level[i]) cnt[x] = 1;
			continue;
		}
		SumSeg<ll> s;
		vector<pi> v;
		int it1 = 0;
		int it2 = 0;
		while(it1<sz(level[i-1]) || it2<sz(level[i])){
			if(it1 == sz(level[i-1])){
				v.eb(mp(level[i][it2], 1));
				it2++;
			}
			else if (it2 == sz(level[i])){
				v.eb(mp(level[i-1][it1], -1));
				it1++;
			}
			else{
				if(level[i-1][it1]>level[i][it2]){
					v.eb(mp(level[i][it2], 1));
					it2++;
				}
				else{
					v.eb(mp(level[i-1][it1], -1));
					it1++;
				}
			}
		}
		unordered_map<int, int> conv;
		set<int> tot;
		for(auto x: v) tot.insert(a[x.f]);
		num = 0;
		for(auto x: tot){
			conv[x] = num;
			num++;
		}
		s.init(num);
		for(auto x: v){
			if(x.s == -1){
				int id = conv[a[x.f]];
				s.upd(id, cnt[x.f] + s.query(id, id));
			}
			else{
				int id = conv[a[x.f]];
				if(id) cnt[x.f] = s.query(0,id -1);
			}
		}
		
	}
	bool ok = true;
	f0r(i, n+1) level[i].clear();
	f0r(i, n) level[lis1[i]].eb(i);
	/*f1r(i, 1, n+1){
		ps("LEVEL", i);
		for(int x: level[i]) ps(x);
	}
	ps("END");*/
	f1r(i, 1, n+1){
		if(sz(level[i]) == 0) break;
		if(i == 1){
			//ok = false;
			for(int x: level[i]) cnt1[x] = 1;

			continue;
		}
		SumSeg<ll> s;
		vector<pi> v;
		int it1 = 0;
		int it2 = 0;
		while(it1<sz(level[i-1]) || it2<sz(level[i])){
			if(it1 == sz(level[i-1])){
				v.eb(mp(level[i][it2], 1));
				it2++;
			}
			else if (it2 == sz(level[i])){
				v.eb(mp(level[i-1][it1], -1));
				it1++;
			}
			else{
				if(level[i-1][it1]>level[i][it2]){
					v.eb(mp(level[i][it2], 1));
					it2++;
				}
				else{
					v.eb(mp(level[i-1][it1], -1));
					it1++;
				}
			}
		}
		unordered_map<int, int> conv;
		set<int> tot;
		for(auto x: v) tot.insert(a[x.f]);
		num = 0;
		for(auto x: tot){
			conv[x] = num;
			num++;
		}
		s.init(num);

		for(int j = sz(v) - 1; j >= 0; j--){
			auto x = v[j];
			if(x.s == -1){
				int id = conv[a[x.f]];
				s.upd(id, cnt1[x.f] + s.query(id, id));
			}
			else{
				int id = conv[a[x.f]];
				if(id+1<num) cnt1[x.f] = s.query(id+1, num-1);
			}
		}
		
	}
	//f0r(i, n) ps(cnt[i], i, "LIS");
	int mxlen= 0;
	f0r(i, n) ckmax(mxlen, lis[i]);
	ll sum = 0;
	f0r(i,n){
		if(lis[i] == mxlen){
			if(sum + cnt[i]>= MOD){
				sum = sum + cnt[i] -MOD;
			}
			else sum = sum + cnt[i];
		}
	}

	f0r(i, n){
		if(lis[i] + lis1[i] -1 == mxlen){
			ll tot = cnt[i]*cnt1[i];
			tot %= MOD;
			if(tot == sum) pr(3);
			else pr(2);
		}
		else{
			pr(1);
		}
	}
	ps();
	return 0;
}