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

void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9 + 7;
const int MAX = 2e3+5;
int n, m, d;
vi a, b;
ll dp[2][2][MAX][MAX];
ll po[MAX];
/// 1 bigger
int par;
ll recurse(int f1, int f2, int rem, int p){
    if(p>=n && rem == 0) return 1;
    if(p>=n) return 0;
    if(dp[f1][f2][rem][p] != -1) return dp[f1][f2][rem][p];
    dp[f1][f2][rem][p] = 0;
    int l = (f1? 0:a[p]);
    int r = (f2? 9:b[p]);
    f1r(i, l, r+1){
        if(p%2 == 1  && i != d) continue;
        if(p%2 == 0 && i == d) continue;
        int _f1 = (f1 | (i > a[p]));
        int _f2 = (f2 | (i < b[p]));


        int _rem = (rem + po[n-p -1]*i)%m;
        //cout << p << " " <<rem << " " <<  _rem << " " << i << endl;
        dp[f1][f2][rem][p] += recurse(_f1, _f2, _rem, p+1);
        if(dp[f1][f2][rem][p]>= MOD) dp[f1][f2][rem][p] -= MOD;
    }
    return dp[f1][f2][rem][p];
}
int main(){
    fast_io();
    cin >> m >> d;
    string astr, bstr;
    cin >> astr >> bstr;
    n = sz(astr);
    f0r(i, n){
        a.eb(astr[i] - '0');
        b.eb(bstr[i] - '0');
    }
    memset(dp, -1, sizeof dp);
    f0r(i, MAX){
        if(i == 0) po[i] = 1;
        else{
            po[i] = po[i-1]*10;
            po[i]%= m;
        }
    }
    cout << recurse(0, 0, 0, 0) << endl;
    return 0;
}