//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
////#pragma GCC optimization ("unroll-loops")
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

ll MOD = 1e9 + 7;

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

const int MAX = 2e5  +5;
const int SZ = (1<<18);
const int MAXT = 1e6;
int n;
const int mod = MOD;
struct Seg{
	struct node{
		int sum, pl;
	}tree[MAXT];
	void clear(){
		fill(tree, tree + MAXT, (node){0, 1});
	}
	void lazydown(int s, int e, int p){
		if(tree[p].pl == 1) return;
		for(int j=2*p; j<2*p+2; j++){
			tree[j].sum = 1ll * tree[j].sum * tree[p].pl % mod;
			tree[j].pl  = 1ll * tree[j].pl  * tree[p].pl % mod;
		}
		tree[p].pl = 1;
	}
	void init(int s, int e, int p, int *a){
		if(s == e){
			tree[p] = {a[s], 1};
			return;
		}
		tree[p].pl = 1;
		int m = (s+e)/2;
		init(s, m, 2*p, a);
		init(m+1, e, 2*p+1, a);
		tree[p].sum = (tree[2*p].sum + tree[2*p+1].sum);
		if(tree[p].sum>=mod) tree[p].sum-=mod;
	}
	void add(int pos, int v, int ps = 0, int pe = 2 * n + 2, int p = 1){
		if(ps == pe){
			tree[p].sum = v;
			tree[p].pl = 1;
			return;
		}
		lazydown(ps, pe, p);
		int pm = (ps+pe)/2;
		if(pos <= pm) add(pos, v, ps, pm, 2*p);
		else add(pos, v, pm+1, pe, 2*p+1);
		tree[p].sum = (tree[2*p].sum + tree[2*p+1].sum);
		if(tree[p].sum>=mod) tree[p].sum-=mod;
	}
	void upd(int pos, int v){
        add(pos, v + query(pos, pos));
	}
	void prod(int s, int e, int v, int ps = 0, int pe = 2 * n + 2, int p = 1){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p].sum = 1ll * v * tree[p].sum % mod;
			tree[p].pl = 1ll * v * tree[p].pl % mod;
			return;
		}
		lazydown(ps, pe, p);
		int pm = (ps+pe)/2;
		prod(s, e, v, ps, pm, 2*p);
		prod(s, e, v, pm+1, pe, 2*p+1);
		tree[p].sum = (tree[2*p].sum + tree[2*p+1].sum);
		if(tree[p].sum>=mod) tree[p].sum -=mod;
	}
	int query(int s, int e, int ps = 0, int pe = 2 * n + 2, int p = 1){
		if(e < ps || pe < s) return 0;
		if(s <= ps && pe <= e) return tree[p].sum;
		lazydown(ps, pe, p);
		int pm = (ps+pe)/2;
		ll val = (query(s, e, ps, pm, 2*p) + query(s, e, pm+1, pe, 2*p+1));
		if(val>=mod) return val-mod;
		return val;
	}
}seg;
vpi queries;
int parent[MAX];
vi adj[MAX];
mi val [MAX];
pi range[MAX];
int idx[MAX];

int num = -1;
int dfs_range(int src, int par){
    num++;
    idx[src] = num;
    int mn = num;
    int mx = num;
    for(int nxt: adj[src]){
        if(nxt == par) continue;
        ckmax(mx, dfs_range(nxt, src));
    }
    range[src] = mp(mn, mx);
    return mx;
}
struct MultiSeg{
    mi sum[2*SZ];
    mi mult[2*SZ];
    mi add[2*SZ];
    MultiSeg(){
        f0r(i, 2*SZ) {
            mult[i] = 1;
            sum[i] = 0;
            add[i] = 0;
        }
    }
    void push(int ind, int L, int R) { // modify values for current node
        sum[ind] *= mult[ind];
        sum[ind] += (R-L+1)*add[ind];
        if (L != R) {
            int M = (L+R)/2;
            mult[2*ind] *= mult[ind];
            mult[2*ind + 1] *= mult[ind];
            add[2*ind] *= mult[ind];
            add[2*ind + 1] *= mult[ind];
            add[2*ind] += add[ind];
            add[2*ind + 1] += add[ind];

        }
        add[ind] = 0;
        mult[ind] = 1;
    }

    void reset(){
        f0r(i, 2*SZ) {
            mult[i] = 1;
            sum[i] = 0;
            add[i] = 0;
        }
        return;
    }
    void pull(int ind) { // recalc values for current node
        sum[ind] = sum[2*ind]+sum[2*ind+1]; }

    /// 0 is add, 1 is for multiplying
    void upd(int lo, int hi,int t, mi inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            if(t == 0) {
                add[ind] = inc;
            }
            else mult[ind] = inc;
            push(ind,L,R); return;
        }
        int M = (L+R)/2;
        upd(lo,hi,t,inc,2*ind,L,M); upd(lo,hi,t,inc,2*ind+1,M+1,R);
        pull(ind);
    }

    mi qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
    }
};

template<int SZ> struct LazySeg {
	mi prod[2*SZ], lazy[2*SZ];
	LazySeg() {
        f0r(i, 2*SZ){
            prod[i] = 1;
            lazy[i] = 1;
        }
	}
	void push(int ind, int L, int R) { /// modify values for current node
		if (L != R) F0R(i,2) lazy[2*ind+i] *= lazy[ind]; /// prop to children
		prod[ind] *= pow(lazy[ind], R-L+1); lazy[ind] = 1;
	} // recalc values for current node
	void pull(int ind) { prod[ind] = prod[2*ind]*prod[2*ind+1]; }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,mi inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2;
		upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
		pull(ind);
	}
	mi qprod(int lo, int hi, int ind=1, int L=0, int R = SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return 1;
		if (lo <= L && R <= hi) return prod[ind];
		int M = (L+R)/2;
		return qprod(lo,hi,2*ind,L,M)*qprod(lo,hi,2*ind+1,M+1,R);
	}
};
//MultiSeg seg;
//Seg seg;
LazySeg<(1<<18)> prod;
vi nadj[MAX];
int main(){
    setIO("");
    int q;
    re(val[0], q);
    int cnt = 1;
    parent[0] = -1;
    f0r(i, q){
        int t; re(t);
        if(t == 1){
            int p, v;
            re(p, v);
            p--;
            adj[cnt].eb(p);
            adj[p].eb(cnt);
            val[cnt] = v;
            parent[cnt] = p;
            queries.eb(mp(1, cnt));
            cnt++;
        }
        else{
            int u; re(u);
            u--;
            queries.eb(mp(2, u));
        }
    }

    seg.clear();
    n = cnt;
    dfs_range(0, -1);
    f0r(i, n){
        assert(0<= idx[i] && idx[i] <= 2e5);
    }
    seg.add(idx[0], val[0].val);
//    seg.upd(idx[0], idx[0], 0, val[0]);


    f0r(i, q){

        int t = queries[i].f;
        int v = queries[i].s;
        if(t == 1){
            assert(v!= 0);
            assert(0<= parent[v] && parent[v]<=2e5);
            int cur = sz(nadj[parent[v]]);
            int par = parent[v];
            if(parent[v] == 0) cur++;
            mi mult = cur+1;
            assert(cur != 0);
            mult = mult/cur;

            //seg.upd(range[par].f, range[par].s, 1, mult);
            assert(0<= range[par].f && 0 <= range[par].s && range[par].f <= 2e5 && range[par].s<= 2e5);
            seg.prod(range[par].f, range[par].s, mult.val);

            prod.upd(range[par].f, range[par].s, mult);

//            seg.upd(idx[v], idx[v], 0, val[v]*prod.qprod(idx[v], idx[v]));
            seg.add(idx[v], (val[v]*prod.qprod(idx[v], idx[v])).val );

            nadj[v].eb(par);
            nadj[par].eb(v);

        }
        else{


//            mi ans = seg.qsum(range[v].f, range[v].s);
            mi ans = seg.query(range[v].f, range[v].s);
            int par = parent[v];
            mi bot;
            if(par == -1) bot = 1;
            else bot = prod.qprod(idx[par], idx[par]);
            assert(bot != 0);
            ps(ans/bot);
        }
    }

    return 0;
}