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
const int MAXN = 15;
const int MAXM = 1e5 + 5;
const int SZ = (1<<17);
int grid[MAXN][MAXM];
int n, m, q;


struct inter{
    int comp = 0;
    int l, r;
    int le[MAXN];
    int ri[MAXN];
    inter(){
        comp = 0;
        l = 0;
        r = 0;
    }
    void init(int c){
        l = c;
        r = c;
        f0r(ro, n){
            le[ro] = ro*MAXM + c;
            ri[ro] = ro*MAXM + c;
        }
        f0r(ro, n){
            if(ro != 0){
                if(grid[ro][c] == grid[ro-1][c]){
                    ckmin(le[ro],le[ro-1]);
                    ckmin(ri[ro],ri[ro-1]);
                }
            }
        }
        set<int> s;
        f0r(ro, n) s.insert(le[ro]);
        comp = sz(s);
    }
};
inter ID;
inter mergeDebug(inter a, inter b){
    inter res;
    res.l = a.l;
    res.r = b.r;
    int tot = a.comp + b.comp;
    f0r(ro, n){
        if(grid[ro][a.r] == grid[ro][b.l] && a.ri[ro] != b.le[ro]){
            int newID = min(a.ri[ro], b.le[ro]);
            int leftID = a.ri[ro];
            int rightID = b.le[ro];
            ps(ro, "EQUALITY", a.r, b.l, leftID, rightID, newID);
            f0r(j, n){
                if(a.le[j] == leftID){
                    a.le[j] = newID;
                }
                if(a.ri[j] == leftID){
                    a.ri[j] = newID;
                }
                if(b.le[j] == rightID){
                    b.le[j] = newID;
                }
                if(b.ri[j] == rightID){
                    b.ri[j] = newID;
                }
            }
            tot--;
        }
    }
    f0r(j, n){
        res.le[j] = a.le[j];
        res.ri[j] = b.ri[j];
    }
    res.comp = tot;
    return res;
}
inter merge(inter a, inter b){
    inter res;
    res.l = a.l;
    res.r = b.r;
    int tot = a.comp + b.comp;
    f0r(ro, n){
        if(grid[ro][a.r] == grid[ro][b.l]&& a.ri[ro] != b.le[ro]){
            int newID = min(a.ri[ro], b.le[ro]);
            int leftID = a.ri[ro];
            int rightID = b.le[ro];
            f0r(j, n){
                if(a.le[j] == leftID){
                    a.le[j] = newID;
                }
                if(a.ri[j] == leftID){
                    a.ri[j] = newID;
                }
                if(b.le[j] == rightID){
                    b.le[j] = newID;
                }
                if(b.ri[j] == rightID){
                    b.ri[j] = newID;
                }
            }
            tot--;
        }
    }
    f0r(j, n){
        res.le[j] = a.le[j];
        res.ri[j] = b.ri[j];
    }
    res.comp = tot;
    return res;
}
inter st [2*SZ];
void pull(int ind){
    st[ind] = merge(st[2*ind], st[2*ind+1]);
}
void build(){
    f0r(i, m){
        st[i+SZ].init(i);
    }
    ROF(i, 1, SZ) pull(i);
}

inter query(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1){
    if(lo>R || L>hi) return ID;
    if(lo<= L && R<= hi) return st[ind];
    int M = (L+R)/2;
    inter leftI = query(lo, hi, 2*ind, L, M);
    inter rightI = query(lo, hi, 2*ind+1, M+1, R);
    if(leftI.comp == 0) return rightI;
    if(rightI.comp == 0) return leftI;
    return merge(leftI, rightI);
 }
int main(){
    setIO("");
    re(n, m, q);
    f0r(i, n){
        f0r(j, m){
            re(grid[i][j]);
        }
    }
    build();
//    inter tmp1;
//    inter tmp2;
//    tmp1.init(0);
//    tmp2.init(1);
//    f0r(j, n){
//        ps(tmp1.le[j], tmp2.le[j], "HUHU");
//    }
//    inter tmp3 = mergeDebug(tmp1, tmp2);
//    ps(tmp3.comp, "HHUHU");
    while(q--){
        int l, r; re(l, r);
        l--; r--;
        inter res = query(l,r);
        ps(res.comp);
    }
    return 0;
}