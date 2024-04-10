#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 350;

int main () {
	int n, m, x, y;
	cin >> n >> m;
	vector <int> a(n), b(m);
	fop (i,0,n) cin >> x >> y, a[i] = (1 << x) | (1 << y);
	fop (i,0,m) cin >> x >> y, b[i] = (1 << x) | (1 << y);
	bool is = true;
	int all = 0;
	fop (i,0,n) {
		int now = 0;
		fop (j,0,m) {
			int k = a[i] & b[j];
			if (__builtin_popcount(k) == 1) all |= k, now |= k;
		}
		if (__builtin_popcount(now) == 2) {
			is = false;
		}
	}
	fop (j,0,m) {
		int now = 0;
		fop (i,0,n) {
			int k = a[i] & b[j];
			if (__builtin_popcount(k) == 1) all |= k, now |= k;
		}
		if (__builtin_popcount(now) == 2) {
			is = false;
		}
	}
	if (__builtin_popcount(all) == 1) {
		fop (i,1,10) if (all & (1 << i)) cout << i << endl;
		return 0;
	}
	if (is) cout << 0 << endl;
	else cout << -1 << endl;
}