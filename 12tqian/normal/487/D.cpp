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

const int MAXN = 1e5 + 5;
const int MAXM = 15;
const int SZ = (1<<17);
int grid [MAXN][MAXM];
int n, m;

struct inter{
    int preventcppfromyellingatme = -1;
    int l;
    int r;
    /// greater than or equal to 0 means up at that index
    /// -1 means left of the board, -2 means right of the board
    /// -3 means infinite loop
    /// -4 is undecided
    int to[MAXM];
    int ou[MAXM];
    inter(){
        l = -1;
        r = -1;
        f0r(i, m) {
            to[i] = -4; ou[i] = 0;
        }
    }
    void init(int ro){
        ro = n-1-ro;
        if(ro<0) return;
        l = n-1-ro;
        r = n-1-ro;
        f0r(i, m) to[i] = -4;
        if(grid[ro][0] == -1) to[0] = -1;
        if(grid[ro][m-1] == 1) to[m-1] = -2;
        f0r(i, m){
            if(grid[ro][i] == 0) to[i] = i;
        }
        f0r(i, m-1){
            if(grid[ro][i] == 1 && grid[ro][i+1] == -1){
                to[i] = -3;
                to[i+1] = -3;
            }
        }
        int st = 0;
        int it1 = 0;
        int it2 = 0;
        while(true){
            if(it1>=m) break;
            if(to[it1] != -4) {
                it1++;
                it2 = it1;
                continue;
            }
            if(grid[ro][it1] == -1){
                to[it1] = to[it1-1];
                it1++;
                it2 = it1;
                continue;
            }
            while(to[it2] == -4){

                it2++;
            }
            assert(it2<=m-1);
            f1r(j, it1, it2){
                to[j] = to[it2];
            }
            it1++;
            it2 = it1;
        }
        f0r(i, m){
            if(to[i] == -1) ou[i] = n-1-ro;
            else if(to[i] == -2) ou[i] = n-1-ro;
        }
    }
};


inter ID;
inter seg[2*SZ];

void merge(inter& ret, inter& i1, inter& i2){
    /// i1 goes into i2
    ret.l = i1.l;
    ret.r = i2.r;
    if(i1.l == -1){
        ret = i2;
        return;
    }
    if(i2.l == -1){
        ret = i1; return;
    }

    f0r(i, m){
        ret.to[i] = i1.to[i];
        if(i1.to[i] == -1 || i1.to[i] == -2){
            ret.ou[i] = i1.ou[i];
        }
        else if(i1.to[i] >= 0){
            int nxt = i1.to[i];
            ret.to[i] = i2.to[nxt];
            if(i2.to[nxt] == -1 || i2.to[nxt] == -2){
                ret.ou[i] = i2.ou[nxt];
            }
        }
    }
}

void pull(int ind){
    merge(seg[ind], seg[2*ind], seg[2*ind+1]);
}
void upd(int idx, int ind = 1, int L = 0, int R = SZ-1){
    if(idx<L || R<idx) return;
    if(L == R){
        seg[ind].init(idx);
        return;
    }
    int M = (L+R)/2;
    upd(idx, 2*ind, L, M);
    upd(idx, 2*ind+1, M+1, R);
    pull(ind);
}
void build(int ind = 1, int L = 0, int R = SZ-1){
    if(L == R){
        seg[ind].init(L);

        return;
    }
    int M = (L+R)/2;
    build(2*ind, L, M);
    build(2*ind+1, M+1, R);
    pull(ind);
}


inter query(int lo, int hi, int ind =1,int L = 0, int R = SZ -1){
    if(R<lo || hi<L) return ID;
    if(lo<=L && R<= hi) return seg[ind];
    int M = (L+R)/2;
    inter le = query(lo, hi, 2*ind, L, M);
    inter ri = query(lo, hi, 2*ind+1, M+1, R);
    inter ret;
    merge(ret, le, ri);
    return ret;
}

void ask(int row, int col){
    inter use = query(n-1-row, n-1);
    if(use.to[col] == -3){
        ps(-1, -1);
    }
    else if(use.to[col] == -1){
        ps(n-1-use.ou[col] +1, -1 + 1);
    }
    else if(use.to[col] == -2){
        ps(n-1-use.ou[col] +1,m + 1);
    }
    else{
        ps(0, use.to[col] + 1);
    }
}
int main(){
    setIO("");
    int q;
    re(n, m, q);
    f0r(i, n){
        string line; re(line);
        f0r(j, m){
            if(line[j] == '^')  grid[i][j] = 0;
            else if(line[j] == '>') grid[i][j] = 1;
            else grid[i][j] = -1;
        }
    }
    build();
    int cnt = 0;
    f0r(i, q){
        char t;
        re(t);
        if(t == 'A'){
            cnt++;
            int r, c; re(r, c);
            r--; c--;
            ask(r, c);

        }

        else{
            int x, y;
            char c;
            re(x, y, c);
            x--; y--;
            int val;
            if(c == '^') val = 0;
            else if (c == '>') val = 1;
            else val = -1;
            grid[x][y] = val;
            upd(n-1-x);
        }
    }

    return 0;
}