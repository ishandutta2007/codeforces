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
const int INF = 1e9;
const int MAX = 55;

int grid[MAX][MAX];
int colsum[MAX][MAX];
int rowsum[MAX][MAX];
int pre[MAX][MAX];
int dp[MAX][MAX][MAX][MAX];
int n;
int rgood(int k, int i, int j){
    return((rowsum[k][j] - (i == 0? 0: rowsum[k][i-1])) == 0? 1: 0);
}
int cgood(int k, int i, int j){
    return((colsum[j][k] - (i == 0? 0: colsum[i-1][k])) == 0? 1: 0);
}
int sum(int a, int b, int c, int d){
    assert(a>=0&&b>=0&&c>=0&&d>=0 && max(max(a, b),max(c, d))<n);
    int res = pre[c][d];
    if(a>0 && b>0) res += pre[a-1][b-1];
    if(a>0) res -= pre[a-1][d];
    if(b>0) res -= pre[c][b-1];
    return res;
}
int solve(int a, int b, int c, int d){
    //ps(a, b, c, d, "HERE");
    if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
    dp[a][b][c][d] = max(c-a+1, d-b+1);
    int h = c-a;
    int l = d-b;
    int best = INF;
    if(l>=h){
        bool ok = false;
        f0r(i, l+1){
            if(cgood(b+i, a, c)){
                ok = true;
                break;
            }
        }
       // if(a==0&&b==0&&c==2&&d==2) ps(ok, "OK");
        if(!ok) {
            dp[a][b][c][d] = l+1;
            return l+1;
        }
        f0r(i, l+1){
            int v = 0;
            if(!cgood(b+i,a, c)){
                continue;
            }
            if(i>0) v += solve(a, b, c, b+i-1);
            if(i<l) v += solve(a, b+i+1, c, d);
//            if(a==0&&b==0&&c==3&&d==3){
//                if(v==1) ps(i, "WHAT");
//            }
            ckmin(best, v);
        }
    }
    else{
        bool ok = false;
        f0r(i, h+1){
            if(rgood(a+i, b, d)){
                ok = true;
                break;
            }
        }
       // if(a==0 && b==0 && c==1 && d==0) ps(ok, "OK");
        if(!ok) {
            dp[a][b][c][d] = h+1;
            return h+1;
        }
        f0r(i, h+1){
            int v = 0;
            if(!rgood(a+i, b, d)){
                continue;
            }
//            if(a==0&&b==0&&c==1&&d==0) {
//                    if(i>0) ps(a, b, a+i-1, d, solve(a, b, a+i-1, d),  "first");
//                    if(i<h) ps(a+i+1, b, c,d , l, h, solve(a+i+1, b,c , d), "second");
//            }
//            ps(v, "BEF");
            if(i>0) v += solve(a, b, a+i-1, d);
            if(i<h) v += solve(a+i+1, b, c, d);
//            ps(v, "VAL");
            ckmin(best, v);
        }
    }
    ckmin(dp[a][b][c][d], best);
    return dp[a][b][c][d];
}
int main(){
    setIO("");
   // int n;
    re(n);
    f0r(i, n){
        string line;
        re(line);
        f0r(j, n){
            if(line[j] == '#') grid[i][j] = 1;
        }
    }

    f0r(i, n){
        f0r(j, n){
            if(j == 0) rowsum[i][j] = grid[i][j];
            else rowsum[i][j] = rowsum[i][j-1] + grid[i][j];
        }
    }
    f0r(j, n){
        f0r(i, n){
            if(i == 0) colsum[i][j] = grid[i][j];
            else colsum[i][j] = colsum[i-1][j] + grid[i][j];
        }
    }
    f0r(i, n){
        int row = 0;
        f0r(j, n){
            row += grid[i][j];
            if(i == 0) pre[i][j] = row;
            else pre[i][j] = pre[i-1][j] + row;
        }
    }
    f0r(a, MAX) f0r(b, MAX) f0r(c, MAX) f0r(d, MAX) dp[a][b][c][d] = -1;
//    ps(solve(0, 0, 1, 0));
//    ps(solve(1, 0, 1, 0));
//    ps(rgood(1, 0, 0));
    ps(solve(0, 0,n-1, n-1));
    return 0;
}