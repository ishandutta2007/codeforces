#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

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
#define rsz resize
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
const int MOD = (119 << 23) + 1, root = 3;
template<class T> struct modular {
	T val;
	explicit operator T() const { return val; }
	modular() { val = 0; }
	modular(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}


	friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) {
		assert(a != 0); return pow(a,MOD-2);
	}
	modular& operator/=(const modular& m) { return (*this) *= inv(m); }

	friend modular operator+(modular a, const modular& b) { return a += b; }
	friend modular operator-(modular a, const modular& b) { return a -= b; }
	friend modular operator*(modular a, const modular& b) { return a *= b; }

	friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;


int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
void genRoots(vcd& roots) { // primitive n-th roots of unity
	int n = sz(roots); double ang = 2*PI/n;
	// is there a way to compute these trig functions more quickly w/o issues?
	F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i));
}
void genRoots(vmi& roots) {
	int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
	roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r;
}

template<class T> void fft(vector<T>& a, const vector<T>& roots, bool inv = 0) {
	int n = sz(a);
	// sort numbers from 0 to n-1 by reverse bit representation
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n>>1;
		for (; j&bit; bit >>= 1) j ^= bit;
		j ^= bit; if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1)
		for (int i = 0; i < n; i += len)
			f0r(j,len/2) {
				int ind = n/len*j; if (inv && ind) ind = n-ind;
				auto u = a[i+j], v = a[i+j+len/2]*roots[ind];
				a[i+j] = u+v, a[i+j+len/2] = u-v;
			}
	if (inv) { T i = T(1)/T(n); trav(x,a) x *= i; }
}
template<class T> vector<T> mult(vector<T> a, vector<T> b) {
	if (!min(sz(a),sz(b))) return {};
	int s = sz(a)+sz(b)-1, n = 1<<size(s);
	vector<T> roots(n); genRoots(roots);
	a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
	f0r(i,n) a[i] *= b[i];
	fft(a,roots,1); a.rsz(s); return a;
}
const int MAX = 5e5 + 5;
char s[MAX];
int main(){
    fast_io();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
		scanf("%s",&s);
        vcd a;
        vcd b;
        a.rsz(n+1);
        b.rsz(n+1);
        f0r(i, n){
            if(s[i] == 'V'){
                a[i] = 1;
            }
            else if (s[i] == 'K'){
                b[n-i-1] = 1;
            }
        }
        reverse(all(a));
        reverse(all(b));
        vcd res = mult<cd>(a, b);
        vi fin;
        f0r(i, sz(res)){
            fin.eb(round(real(res[i])));
        }
        reverse(all(fin));
        vi check;
        check.rsz(n+1);
        f0r(i, sz(fin)){
            if(fin[i]>0){
                int v = abs(i +1 -n );
                if(v<=n) check[v] = 1;
            }
        }
        set<int> ans;
        f1r(i, 1, n+1){
            int cur = i;
            bool ok = true;
            while(cur<n){
                if(check[cur]>= 1){
                    ok = false;
                    break;
                }
                cur += i;
            }
            if(ok) ans.ins(i);
        }
        printf("%d\n",sz(ans));
        int cnt = 0;
        for(auto x: ans)
		{

			if(cnt!=0) printf(" ");
			cnt++;
			printf("%d",x);
		}puts("");
    }

    return 0;
}