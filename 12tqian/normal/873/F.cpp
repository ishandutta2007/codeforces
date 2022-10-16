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
typedef vector<pd> vpd;
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

const int MAX = 2e5 + 5;


struct SuffixArray {
	string S; int N;
	void init(string _S) { S = _S, N = sz(S); genSa(), genLcp(); }
	vi sa, isa; // indices of suffixes in sorted order, inverses
	void genSa() {
		sa.resz(N), isa.resz(N); iota(all(sa),0);
		sort(all(sa),[&](int a, int b) { return S[a] < S[b]; });
		F0R(i,N) {
			bool same = i && S[sa[i]] == S[sa[i-1]];
			isa[sa[i]] = same ? isa[sa[i-1]] : i;
		}
		for (int len = 1; len < N; len *= 2) {
			// sufs currently sorted by first len chars
			vi is(isa), s(sa), nex(N); iota(all(nex),0);
			FOR(i,-1,N) { // rearrange sufs by 2*len
				int s1 = (i == -1 ? N : s[i])-len;
				if (s1 >= 0) sa[nex[isa[s1]]++] = s1;
			} // to make faster, break when all ints in sa distinct
			F0R(i,N) { // update isa for 2*len
				bool same = i && sa[i-1]+len < N
							  && is[sa[i]] == is[sa[i-1]]
							  && is[sa[i]+len] == is[sa[i-1]+len];
				isa[sa[i]] = same ? isa[sa[i-1]] : i;
			}
		}
	}
	vi lcp; // common prefix of every two indices in sa
	void genLcp() { // Kasai's Algo
		lcp = vi(N-1); int h = 0;
		F0R(i,N) if (isa[i]) {
			for (int j=sa[isa[i]-1]; j+h<N && S[i+h]==S[j+h]; h++);
			lcp[isa[i]-1] = h; if (h) h--;
		}
		/// if we cut off first chars of two strs with lcp h
		/// then remaining portions still have lcp h-1
		/// R.init(lcp);
	}
	/**RMQ<int> R;
	int getLCP(int a, int b) { // lcp of suffixes starting at a,b
		if (max(a,b) >= N) return 0;
		if (a == b) return N-a;
		int t0 = isa[a], t1 = isa[b];
		if (t0 > t1) swap(t0,t1);
		return R.query(t0,t1-1);
	}*/
};
int bad[MAX];
SuffixArray sa;
template<class T> struct Seg {
	const T ID = 1e9; // comb(ID,b) must equal b
	T comb(T a, T b) { return min(a, b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};
int sz;
Seg<int> seg;
vi loc;
vi use;

int binLeft(int id){
    int l = 0;
    int r = id;
    int val = seg.query(id, id);
    while(abs(l-r)>1){
        int m = (l+r)/2;
        if(seg.query(m, id)>=val){
            r = m;
        }
        else l = m+1;
    }
    if(l>r) swap(l, r);
    if(seg.query(l, id)>=val) return l;
    return r;
}
int binRight(int id){
    int l = id;
    int r = sz-1;
    int val = seg.query(id, id);
    while(abs(l-r)>1){
        int m = (l+r)/2;
        if(seg.query(id, m) >=val) l = m;
        else r = m-1;
    }
    if(l>r) swap(l, r);
    if(seg.query(id, r)>=val) return r;
    return l;
}
int tmp[MAX];
int pre[MAX];

int main(){
    int n;
    re(n);
    string s;
    re(s);
    string t; re(t);
    reverse(all(s));
    reverse(all(t));
    f0r(i, n) bad[i] = t[i] - '0';
    sa.init(s);
    ll ans = 0;
    f0r(i, n){
        if(bad[i] == 0){
            ckmax(ans, (ll)((n-1) - i + 1));
            break;
        }
    }
    if(n == 1){
        ps(ans);
        return 0;
    }
    vi lcp = sa.lcp;
    sz = sz(lcp);
    f0r(i, n){
        if(bad[sa.sa[i]] == 0){
            loc.eb(1);
        }
        else loc.eb(0);
    }
    f0r(i, n){
        if(i == 0) pre[i] = loc[i];
        else pre[i] = pre[i-1] + loc[i];
    }
    seg.init(sz);
    f0r(i, sz) seg.upd(i, lcp[i]);
    f0r(i, sz){
        int l = binLeft(i);
        int r = binRight(i);
        ll val = seg.query(i, i);
        val *= (pre[r+1] - (l == 0? 0 : pre[l-1]));
        ckmax(ans, val);
    }
    ps(ans);
    return 0;
}