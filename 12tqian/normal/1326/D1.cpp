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
const int BASE = 31;
const int MAX = 1e6 + 5;
mi po[MAX];
mi ipo[MAX];
struct hsh{
    vmi h;
    vmi rh;
    int n;
    hsh(){
 
    }
    mi sum(int i, int j){
        if(i>j) return 0;
        return (h[j] - (i == 0? 0: h[i-1]))*ipo[i];
    }
    mi rsum(int i, int j){
        if(i>j) return 0;
        return (rh[j] - (i == 0? 0: rh[i-1]))*ipo[n-j -1];
    }
    int pal(int a, int b){
        if(!(-1<=a && a<=n)) return 0;
        if(!(-1<=b && b<=n)) return 0;
        mi h1 = sum(0, a) + po[a+1]*sum(b, n-1);
        mi h2 = rsum(b, n-1) + po[n-1-b+1]*rsum(0, a);
        if(h1 == h2) return 1;
        return 0;
    }
    void init(string s){
        n = sz(s);
        f0r(i, n){
            if(i == 0) h.eb(s[i]*po[i]);
            else h.eb(h[sz(h) - 1] + po[i]*s[i]);
        }
        f0r(i, n){
            if(i == 0) rh.eb(s[i]*po[n-1-i]);
            else rh.eb(rh[sz(rh) - 1] + po[n-1-i]*s[i]);
        }
    }
};
vi manacher(string s) {
	string s1 = "@"; trav(c,s) s1 += c, s1 += "#";
	s1.back() = '&';
	vi ans(sz(s1)-1); int lo = 0, hi = 0;
	FOR(i,1,sz(s1)-1) {
		if (i != 1) ans[i] = min(hi-i,ans[hi-i+lo]);
		while (s1[i-ans[i]-1] == s1[i+ans[i]+1]) ans[i] ++;
		if (i+ans[i] > hi) lo = i-ans[i], hi = i+ans[i];
	}
	ans.erase(begin(ans));
	F0R(i,sz(ans)) if ((i&1) == (ans[i]&1)) ans[i] ++;
	return ans;
}
int main(){
    setIO("");
    f0r(i, MAX){
        if(i == 0) po[i] = 1;
        else po[i] = po[i-1]*BASE;
    }
    mi inve = 1/mi(BASE);
    f0r(i, MAX){
        if(i == 0) ipo[i] = 1;
        else ipo[i] = ipo[i-1]*inve;
    }
    int tt;
    re(tt);
    while(tt--){
        string s;
        re(s);
        int n = sz(s);
      //  s = s + s;
        vi v = manacher(s);
        hsh h;
        h.init(s);
        int len = -1;
        pi bes = mp(0, n);
        f0r(i,sz(v)){
            int l, r;
            if(i%2 == 0){
                l = i/2 - (v[i] - 1)/2;
                r =  i/2 + (v[i] - 1)/2;
 
            }
            else{
                if(v[i] == 0) continue;
                l = i/2 - v[i]/2+1;
                r = i/2+1 + v[i]/2-1;
            }
           // ps(i,v[i],  l, r, "PAL");
            int mn = min(l, n-1 - (r+1)+1);
            if(h.pal(mn-1, n - 1 - (mn-1))){
                int lo, hi;
                if(l<= (n-1 - (r+1) + 1)){
                    lo = r;
                    hi = (n-1 - (mn-1));
                }
                else{
                    lo = mn-1;
                    hi = l;
                }
                //ps(lo, hi,l, r, "HUHH");
                if((n-1-hi)+1 + lo + 1>len){
                    len = (n-1-hi)+1 + lo + 1;
                    bes = mp(lo, hi);
                }
            }
 
        }
        string t = "";
        assert(bes.f>=-1 && bes.s>=-1 && bes.f<n+1 && bes.s<n+1);
        f0r(i, bes.f+1) t += s[i];
        f1r(i, bes.s, n) t += s[i];
        ps(t);
      //  ps(v);
 
       // if(h.pal(-1,  4)) ps("HUH");
    }
    return 0;
}