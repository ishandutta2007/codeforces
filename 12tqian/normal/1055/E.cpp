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
vi a;
int n, s, m, k;
const int MAX = 1500 + 5;
const int INF = 1e9;
int oc[MAX];
int pre[MAX];
vpi seg;
vpi fin;
int dp[MAX][MAX];
int mx[MAX][MAX];
int sub[MAX][MAX];
int last[MAX];
int sum(int l, int r){
    return pre[r] - (l == 0? 0:pre[l-1]);
}
int check(int x){
    f0r(i, n){
        if(a[i]<=x) oc[i] = 1;
        else oc[i] = 0;
    }
    f0r(i, n){
        if(i==0) pre[i] = oc[i];
        else pre[i] = pre[i-1] + oc[i];
    }
    /// maximum covering with at most m of seg
    f0r(i, MAX) f0r(j, MAX) dp[i][j] = 0;
    f0r(i, MAX) f0r(j, MAX) mx[i][j] = 0;
    //f0r(i, MAX) f0r(j, MAX) sub[i][j] = -INF;
    int ret = 0;
   // ps(x ,"HUH");
    /// dp[i][j] is maximum covered with i intervals, up to j
    f0r(i, s){
        f1r(j, 1, m+1){
          //  ps("PEH");
            if(j == 1){
                //ps("HERE", i, fin, sz(fin));
             //   ps("HERE", s);
           //  ps("HERE",fin);
                  //  ps("HERE", i, s, fin);
                dp[1][i] = sum(fin[i].f, fin[i].s);
           // ps("FIN");
            }
            else{
                 //   ps("ST");
                if(last[i] != i) {
                    ckmax(dp[j][i], pre[fin[i].s] - pre[fin[last[i]].s] + dp[j-1][last[i]]);
                }
                if(last[i] > 0){
                    ckmax(dp[j][i], mx[j-1][last[i] - 1] + sum(fin[i].f, fin[i].s));
                }
        //    ps("HUH");
            }
           // ps("ST");
            if(i == 0){
                mx[j][i] = dp[j][i];
            }
            else mx[j][i] = max(dp[j][i], mx[j][i-1]);
           // ps("HUH");
            ckmax(ret, dp[j][i]);
            //ps("EH");
        }
    }

    if(ret>=k) return 1;
    return 0;
}
int once[MAX];
int main(){
//    int n, s, m, k;
    re(n, s, m, k);
    f0r(i, n){
        int ai;
        re(ai);
        a.eb(ai);
    }
    f0r(i, s){
        int li, ri;
        re(li, ri);
        li--; ri--;
        seg.eb(mp(li,ri));
    }
    sort(all(seg));
    int it1 = 0;
    int it2 = 0;
    while(it1 <s && it2<s){
        while(it2 < s && seg[it1].s>= seg[it2].s){
            it2++;
        }
        fin.eb(seg[it1]);
        it1 = it2;
    }
    s = sz(fin);
    f0r(i, s){
        f0r(j, i+1){
            if(fin[j].s>=fin[i].f){
                last[i] = j;
              //  ps(i, last[i], "LAST");
                break;
            }
        }
    }

    int l = 1;
    int r = 1e9+5;
    while(abs(l-r)>1){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    if(l>r) swap(l, r);
    if(min(l, r)>1e9) {
        ps(-1); return 0;
    }
    if(check(l)) ps(l);
    else ps(r);
    return 0;
}