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
 
const ll MOD = 998244353;
 
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
namespace factorBasic {
	vector<pair<ll,int>> factor(ll x) {
		vector<pair<T,int>> pri;
		for (T i = 2; i*i <= x; ++i) if (x % i == 0) {
			int t = 0;
			while (x % i == 0) x /= i, t ++;
			pri.pb({i,t});
		}
		if (x > 1) pri.pb({x,1});
		return pri;
	}
	/* Note:
	 * number of operations needed s.t.
	 *				  phi(phi(...phi(n)...))=1
	 * is O(log n).
	 * Euler's theorem: a^{\phi(p)}\equiv 1 (mod p), gcd(a,p)=1
	 */
	ll phi(ll x) {
		trav(a,factor(x)) x -= x/a.f;
		return x;
	}
	void tour(vector<pair<ll,int>>& v,
		vector<ll>& V, int ind, ll cur) {
			if (ind == sz(v)) V.pb(cur);
			else {
				T mul = 1;
				F0R(i,v[ind].s+1) {
					tour(v,V,ind+1,cur*mul);
					mul *= v[ind].f;
				}
			}
		}
	vector<ll> getDivi(ll x) {
		auto v = factor(x);
		vector<ll> V; tour(v,V,0,(ll)1); sort(all(V));
		return V;
	}
}
const int MAX = 3e5 + 5;
const ll INF = 1e17;
using namespace factorBasic;
vl divisors;
map<ll, int> conv;
map<ll, int> num;
vl pri;
static vector<pair<int, ll>> adj[MAX];
//n lon n dijkstra using priority queue, distance from src to dest
ll dist[MAX];
int par[MAX];
void dijkstra(int st, int end) {
    fill(dist, dist + MAX, INF);
 
    dist[st] = 0;
 
    // <distance, <previous vertex, current vertex>>
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>> >, greater<pair<ll, pair<int ,int>> > > pq;
    pq.emplace(0, make_pair(st, st));
 
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
 
        ll d = top.first;
        int prev = top.second.first;
        int cur = top.second.second;
 
        if(d > dist[cur])
            continue;
 
        par[cur] = prev;
 
        for(auto v: adj[cur]){
            int nxt = v.first;
            ll w = v.second;
            if (dist[nxt] > dist[cur] + w) {
                dist[nxt] = dist[cur] + w;
                pq.emplace(dist[nxt], make_pair(cur, nxt));
            }
        }
    }
}
ll getNum(ll x){
    ll tot = 1;
    for(auto p: pri){
        int cnt = 0;
        while(x%p == 0) {
            x/=p;cnt++;
        }
        tot*=(cnt+1);
    }
    return tot;
}
mi paths[MAX];
 
int main(){
    setIO("");
    ll d; re(d);
    divisors = getDivi(d);
    auto fact = factor(d);
    for(auto x: fact) pri.eb(x.f);
    for(auto x: divisors){
        num[x] = getNum(x);
    }
    int cnt = 0;
    for(auto x: divisors){
        conv[x] = cnt;
        cnt++;
    }
 
 
    for(auto x: divisors){
        for(auto p: pri){
            if(x%p != 0) continue;
            ll y = x/p;
            ll red = y;
            while(red%p == 0) red/=p;
            ll we = num[red];
            int xi = conv[x];
            int yi = conv[y];
            adj[xi].eb(mp(yi, we));
            adj[yi].eb(mp(xi, we));
//            ps(x, y, we);
        }
    }
    int sz = sz(divisors);
    dijkstra(0, sz-1);
    vector<pair<ll, int>> dists;
    f0r(i, sz){
        dists.eb(mp(dist[i], i));
    }
    sort(all(dists));
    paths[0] = 1;
    f0r(i, sz-1){
        int v = dists[i].s;
        ll len =  dists[i].f;
        for(auto e: adj[v]){
            int nxt = e.f;
            ll we = e.s;
            if(dist[nxt] == len + we){
                paths[nxt] += paths[v];
            }
        }
    }
//    f0r(i,sz) ps(paths[i], divisors[i]);
    int q;
    re(q);
    f0r(t, q){
        ll u, v;re(u, v);
        ll g = __gcd(u, v);
        u/=g;
        v/=g;
        ps(paths[conv[u]]*paths[conv[v]]);
    }
    return 0;  
}