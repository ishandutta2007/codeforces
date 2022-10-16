#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
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
const int MAX = 205;
const int INF = 1e7;
/// first value is the minimum length, the other is character
/// used
pair<pi, int> rev[MAX][MAX][MAX];
pi dp[MAX][MAX][MAX];
inline int get(char c){
    if(c == '(') return 1;
    return -1;
}
inline void change(pi& a, pi b, pair<pi, int>&c, int use, int x, int y, int z){
    if(a.f>b.f+1){
        a = mp(b.f+1, use);
        c = mp(mp(x, y), z);
    }
}

int main(){
    string s, t;
    re(s, t);
    f0r(i, MAX) f0r(j, MAX) f0r(k, MAX) dp[i][j][k] = mp(INF, INF);
    rev[0][0][0] = mp(mp(-1, -1), -1);
    dp[0][0][0] = mp(0, -2);
    f0r(a, sz(s)+1){
        f0r(b, sz(t)+1){
            if(a == 0 && b == 0) {
                f0r(d, MAX-1){
                change(dp[a][b][d+1], dp[a][b][d], rev[a][b][d+1], 1, a, b, d);
                }
                for(int d = MAX-1; d>= 1; d--){
                    change(dp[a][b][d-1], dp[a][b][d], rev[a][b][d-1], -1, a, b, d);
                }
            }
            f0r(d, MAX){
                int nxta = a;
                int nxtb = b;
                int nxtd = d;
                if(a>0 && s[a-1] == '('){
                    nxta--;
                }
                if(b>0 && t[b-1] =='('){
                    nxtb--;
                }
                nxtd--;
                if(nxtd>=0&&nxtd<MAX){
                    change(dp[a][b][d], dp[nxta][nxtb][nxtd], rev[a][b][d],  1, nxta, nxtb, nxtd);
                }
                nxta = a;
                nxtb = b;
                nxtd = d;
                if(a>0 && s[a-1] == ')'){
                    nxta--;
                }
                if(b>0 && t[b-1] ==')'){
                    nxtb--;
                }
                nxtd++;
                if(nxtd>=0 && nxtd<MAX){
                    change(dp[a][b][d], dp[nxta][nxtb][nxtd], rev[a][b][d], -1, nxta, nxtb, nxtd);
                }
            }
            f0r(d, MAX-1){
                change(dp[a][b][d+1], dp[a][b][d], rev[a][b][d+1], 1, a, b, d);
            }
            for(int d = MAX-1; d>= 1; d--){
                change(dp[a][b][d-1], dp[a][b][d], rev[a][b][d-1], -1, a, b, d);
            }
        }
    }
    string res = "";
    int cura = sz(s);
    int curb = sz(t);
    int curd = 0;
    while(true){
        int use = dp[cura][curb][curd].s;
       // ps(cura, curb, curd, dp[cura][curb][curd]);
        if(use == -2) break;
        if(use == 1){
            res += "(";
        }
        if(use ==-1){
            res += ")";
        }
        auto x = rev[cura][curb][curd];
        cura = x.f.f;
        curb = x.f.s;
        curd = x.s;

    }
    reverse(all(res));
    ps(res);
    return 0;
}