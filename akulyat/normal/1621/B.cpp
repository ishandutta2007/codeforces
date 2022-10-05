#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }

struct tup {
	int l, r, c;
};

bool viv = false;
int n;
vector<tup> v;


void solve() {
	cin >> n;
	v.resize(n);

	int L = mod;
	int R = -mod;
	map<int, int> bestl, bestr;
	map<pii, int> best;
	for (auto &[l, r, c] : v) {
		cin >> l >> r >> c;		

		if (bestl.count(l) == 0)
			bestl[l] = c;
		else
			bestl[l] = min(bestl[l], c);
		if (bestr.count(r) == 0)
			bestr[r] = c;
		else
			bestr[r] = min(bestr[r], c);
		if (best.count({l, r}) == 0)
			best[{l, r}] = c;
		else
			best[{l, r}] = min(best[{l, r}], c);

		L = min(l, L);
		R = max(r, R);

		int ans = 2 * mod;
		ans = min(ans, bestl[L] + bestr[R]);
		if (best.count({L, R}))
			ans = min(ans, best[{L, R}]);
		cout << ans << '\n';
	}
	cout << '\n';

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}