//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
//////#pragma GCC optimization ("unroll-loops")
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
		//cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}
using namespace io;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9+7;
struct mi {
	ll val;
	explicit operator ll() const { return val; }
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
const int SZ = (1<<18);
const ll INF = 1e16;
vector<pair<int, ll>> dadj[MAX];
vi adj[MAX];
map<pi, ll> we;
inline pi cp(int u, int v){
    return mp(min(u, v), max(u, v));
}
int vis[MAX];
int cycle[MAX];
int head = -1;
int tail = -1;
vi cyc;
vl val;

ll hi = 0;
ll dfs_max_depth(int src, int par){
    ll mx = 0;
    multiset<ll, greater<ll>> legs;
    for(auto nxt: dadj[src]){
        if(nxt.f == par) continue;
        if(cycle[nxt.f]) continue;
        ll leg = nxt.s + dfs_max_depth(nxt.f, src);
        ckmax(mx, leg);
        legs.insert(leg);
        //ckmax(mx, nxt.s + dfs_max_depth(nxt.f, src));
    }
    if(sz(legs)>= 2){
        ll tot = 0;
        int cnt = 0;
        for(auto x: legs){
            tot += x;
            cnt++;
            if(cnt == 2) break;
        }
        ckmax(hi, tot);
    }
//    if(mx<0) ps("HUHUHUH");
    return mx;
}
void dfs_tail(int src, int par){
    vis[src] = par;
    if(tail != -1) return;
    for(int nxt: adj[src]){
        if(tail != -1) return;
        if(nxt == par) continue;
        if(vis[nxt] != -1){
            head = nxt;
            tail = src;
            return;
        }
        else{
            dfs_tail(nxt, src);
        }
    }
}
template<class T, int SZ> struct MaxSeg {
	T mx[2*SZ], lazy[2*SZ];
	int bes[2*SZ];
	MaxSeg() {
		memset(mx,0,sizeof mx);
		memset(lazy,0,sizeof lazy);
		f0r(i, SZ) bes[SZ + i] = i;
		build();
	}
	void push(int ind, int L, int R) { // modify values for current node
		mx[ind] += lazy[ind];
		if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
		lazy[ind] = 0; // pushed lazy to children
	}
	void pull(int ind) { // recalc values for current node
		if(mx[2*ind]>=mx[2*ind+1]){
            bes[ind] = bes[2*ind];
            mx[ind] = mx[2*ind];
		}
		else{
            bes[ind] = bes[2*ind+1];
            mx[ind] = mx[2*ind+1];
		}
    }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ-1) {
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
	T qmax(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return -INF;
		if (lo <= L && R <= hi) return mx[ind];
		int M = (L+R)/2;
		return max(qmax(lo,hi,2*ind,L,M), qmax(lo,hi,2*ind+1,M+1,R));
	}
	pair<T, int> query(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return mp(-INF, -1);
		if (lo <= L && R <= hi) return mp(mx[ind], bes[ind]);
		int M = (L+R)/2;
		return max(query(lo,hi,2*ind,L,M), query(lo,hi,2*ind+1,M+1,R));
	}
	pair<T, int> secon(){
        auto x = query(0, SZ-1);
        upd(x.s, x.s, -INF);
        auto y = query(0, SZ-1);
        upd(x.s, x.s, INF);
        return y;
	}
};
template<class T, int SZ> struct MinSeg {
	T mx[2*SZ], lazy[2*SZ];
	int bes[2*SZ];
	MinSeg() {
		memset(mx,0,sizeof mx);
		memset(lazy,0,sizeof lazy);
		f0r(i, SZ) bes[SZ + i] = i;
		build();
	}
	void push(int ind, int L, int R) { // modify values for current node
		mx[ind] += lazy[ind];
		if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
		lazy[ind] = 0; // pushed lazy to children
	}
	void pull(int ind) { // recalc values for current node
		if(mx[2*ind]<=mx[2*ind+1]){
            bes[ind] = bes[2*ind];
            mx[ind] = mx[2*ind];
		}
		else{
            bes[ind] = bes[2*ind+1];
            mx[ind] = mx[2*ind+1];
		}
    }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ-1) {
	    if(lo>hi) return;
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
	T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return INF;
		if (lo <= L && R <= hi) return mx[ind];
		int M = (L+R)/2;
		return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
	}
	pair<T, int> query(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return mp(INF, -1);;
		if (lo <= L && R <= hi) return mp(mx[ind], bes[ind]);
		int M = (L+R)/2;
		return min(query(lo,hi,2*ind,L,M), query(lo,hi,2*ind+1,M+1,R));
	}
	pair<T, int> secon(){
        auto x = query(0, SZ-1);
        upd(x.s, x.s, INF);
        auto y = query(0, SZ-1);
        upd(x.s, x.s, -INF);
        return y;
	}
};
MaxSeg<ll, SZ> sum;
MinSeg<ll, SZ> diff;
void print(){
    int sz = sz(cyc);
    ps("SUM: ");
    f0r(i, sz) pr(sum.qmax(i, i), " ");
    ps();
    ps("DIFF:");
    f0r(i, sz) pr(diff.qmin(i, i),  " ");
    ps();
}
int main(){
    int n; re(n);
    f0r(i, n) vis[i] = -1;
    f0r(i ,n){
        int u, v, l; re(u, v, l);
        u--; v--;
        dadj[u].eb(mp(v, l));
        dadj[v].eb(mp(u, l));
        adj[u].eb(v);
        adj[v].eb(u);
        we[cp(u, v)] = l;
    }
    dfs_tail(0, -2);
    int cur = tail;
    while(true){
        cyc.eb(cur);
        cur = vis[cur];
        if(cyc[sz(cyc) - 1] == head) break;
    }
    for(auto x: cyc) cycle[x] = 1;
    for(auto x: cyc) val.eb(dfs_max_depth(x, -1));
    int sz = sz(cyc);
    f0r(i, sz){
        sum.upd(i, i, val[i]);
        diff.upd(i, i, -val[i]);
        ll ad = we[cp(cyc[i], cyc[(i+1)%sz])];
        if(i!= sz-1) {
            sum.upd(i+1, sz-1, ad);
            diff.upd(i+1, sz-1, ad);
        }

    }
    ll full = 0;
    f0r(i, sz){
        full += we[cp(cyc[i], cyc[(i+1)%sz])];
    }
    ll ans = INF;
//    if(n == 5000) ps(sz(cyc));
    f0r(i, sz){
        auto q1 = sum.query(0, sz-1);
        auto q2 = diff.query(0, sz-1);
        if(q1.s == q2.s){
            auto s1 = sum.secon();
            auto s2 = diff.secon();
//            assert(q1.s != s2.s && s1.s != q2.s);
            ckmin(ans, max(max(hi, q1.f - s2.f), max(hi, s1.f - q2.f)));
        }
        else{
            ckmin(ans, max(q1.f - q2.f, hi));
//            if(q1.f - q2.f == 9473) ps(i, q1, q2);
        }
        int bef = (i-1+sz)%sz;
        int aft = (i+1)%sz;
        ll sub = we[cp(cyc[i], cyc[aft])];
        sum.upd(0, sz-1, -sub);
        sum.upd(i, i, full);
        diff.upd(0, sz-1,-sub);
        diff.upd(i, i, full);
    }
    ps(ans);
    return 0;
}