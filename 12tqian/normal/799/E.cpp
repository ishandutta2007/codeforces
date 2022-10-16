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
		//cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
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
const ll INF = 1e18;
const int MAX = 2e5 + 5;
ll c[MAX];
vi x;
vi y;
int mark[MAX];
vl type[4];
ll pre[4][MAX];
struct query{
    multiset<pair<ll, int>> use;
    multiset<pair<ll, int>> other;
    ll sum;
    int cur = 0;
    query(){
        sum = 0;
        cur = 0;

    }
    void preIns(ll r, int s){
        use.insert(mp(r, s));
        sum += r;
        cur++;
    }
    void ins(ll r, int s){
        if(sz(use) == 0){
            preIns(r, s);
            return;
        }
        assert(sz(use)>0);
        auto ed = *(use.rbegin());
        if(ed.s>r){
            use.erase(use.find(ed));
            sum -= ed.f;
            other.insert(ed);
            use.insert(mp(r, s));
            sum += r;
        }
        else{
            other.insert(mp(r, s));
        }
    }
    void rem(ll r, int s){
        if(use.find(mp(r, s))!= use.end()){
            use.erase(use.find(mp(r, s)));
            sum -= r;
            if(sz(other) == 0){
                cur--;
                //assert(false);
                return;
            }
            else{
                auto st = *(other.begin());
                other.erase(other.begin());
                use.insert(st);
                sum += st.f;
            }
        }
        else{
            assert(other.find(mp(r, s)) != other.end());
            other.erase(other.find(mp(r, s)));
        }
    }
    ll ask(int k){
        if(k == 0) return 0;
        if(k<0) return -1;
        if(k>cur){
            return -1;
        }
        assert(cur = sz(use));
        while(cur>k){
            auto ed = *use.rbegin();
            use.erase(use.find(ed));
            sum -= ed.f;
            other.insert(ed);
            cur--;
        }
        return sum;
    }
};
query q;
int main(){
    int n, m, k;
    re(n, m, k);
    f0r(i, n){
        re(c[i]);
    }
    int a;
    re(a);
    f0r(i, a){
        int xi;
        re(xi);
        xi--;
        x.eb(xi);
    }
    int b;
    re(b);
    f0r(i, b){
        int yi;
        re(yi);
        yi--;
        y.eb(yi);
    }
    f0r(i, a){
        mark[x[i]]+= 1;
    }
    f0r(i, b){
        mark[y[i]] += 2;
    }
    f0r(i,n){
        type[mark[i]].eb(c[i]);
    }
    f0r(i, 4) sort(all(type[i]));

    f0r(i, 4){
        f0r(j, n){
            if(j == 0){
                if(j<sz(type[i])) pre[i][j] = type[i][j];
            }
            else{
                if(j<sz(type[i])){
                    pre[i][j] = type[i][j] + pre[i][j-1];
                }
            }
        }
    }
//    ps(type[0]);
//    ps(type[1]);
//    ps(type[2]);
//    ps(type[3]);
    //int num = min(min(k, sz(type[1])), sz(type[2]));
    int num = min(k, sz(type[3]));
  //  ps(num, "NUM");
    int lef = (k - num);
    if(lef> min(sz(type[1]), sz(type[2]))){
        ps(-1);
        return 0;
    }

    for(auto it: type[0]){
        q.preIns(it, 0);
    }
    f1r(i, lef, sz(type[1])){
        q.preIns(type[1][i], 1);
    }
    f1r(i, lef, sz(type[2])){
        q.preIns(type[2][i], 2);
    }
    f1r(i, num, sz(type[3])){
        q.preIns(type[3][i], 3);
    }
    int i1 = lef;
    int i2 = lef;
    int i3 = num-1;
//    ps(lef, "LEF");
    ll bes = INF;
    while(true){

     //   ps( m-(i1 + 1 + i2 + 1 +lef), "ASKING");
//     ps("HUHUH");
//     ps(q.use, q.other);
//     ps(m-(i1 + 1 + i2 + 1 +lef));
        ll ad = q.ask(m-(i1  + i2 +i3+1));
     //   ps("DIDN'T MAKE IT");
        ll val = pre[1][i1-1] + pre[2][i2-1] + pre[3][i3] + ad;
        if(ad != -1)ckmin(bes, val);
        if(i3<0) break;
        if(i1>=sz(type[1])) break;
        if(i2>=sz(type[2])) break;
        q.rem(type[1][i1], 1);
        q.rem(type[2][i2], 2);
        q.ins(type[3][i3], 3);
        i3--;
        i1++;
        i2++;
    }
    if(bes == INF) {
          //  ps("ASD");
        ps(-1);
        return 0;
    }
    ps(bes);
  //  if(bes != 332237) ps(bes);
 //   else ps(301115);

    return 0;
}