#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
 
using namespace std;
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second
 
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
 
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
const ll inf = 1e16;
 
const int MOD = 1e9 + 7;
typedef decay<decltype(MOD)>::type T;
struct mi {
	T val;
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const long long& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD; }
	friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
	friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) { val = (long long) val * m.val % MOD;
		return *this; }
	friend mi pow(mi a, long long p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; }
	friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
 const int N = 3e5 + 5;
 const int L = 19;
 
int lift[300005][19];
ll gold[300005];
ll cost[300005];
int depth[300005];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 
	int q; cin >> q;
	int a, c; cin >> a >> c;
 
	gold[0] = a;
	cost[0] = c;
 
	f0r(i, 300005) {
		f0r(j, 19) {
			lift[i][j] = -1;
		}
	}
	depth[0] = 0;
	int t = 0;
 
	for (int i = 1; i <= q; i++) {
		int t; cin >> t;
 
		if (t == 1) {
			int p; cin >> p >> a >> c;
			gold[i] = a;
			cost[i] = c;
 
			lift[i][0] = p;
 
			for (ll j = 1; j < 19; j++) {
				if (lift[i][j-1] != -1)
					lift[i][j] = lift[lift[i][j-1]][j-1];
			}
			depth[i] = depth[p] + 1;
		} else {
			int v, w; cin >> v >> w;
			ll cst = 0;
			int bought = 0;
			
			while (gold[v] > 0 && w > 0) {
				int buyfrom = v;
				bool cont = 1;

				while (cont) {
					++t;
					int nxt = buyfrom;
					cont = 0;
					f0r(j, 19) {
						ll tst = lift[buyfrom][j];
						if (tst == -1 || gold[tst] == 0) {
							break;
						} else {
							nxt = tst;
						}
					}

					if (buyfrom != nxt) {
						cont = 1;
						buyfrom = nxt;
					}
				}

 
				if (gold[buyfrom] >= w) {
					gold[buyfrom] -= w;
 
					cst += w * cost[buyfrom];
					bought += w;
					w = 0;
				} else {
					w -= gold[buyfrom];
 
					cst += gold[buyfrom] * cost[buyfrom];
					bought += gold[buyfrom];
					gold[buyfrom] = 0;
				}

			}

			cout << bought << " " << cst << endl;
			assert(t <= N * L * 4);


 
		}
 
 
 
 
	}
	
 
	
}