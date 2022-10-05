#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 
 
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
 
 
bool viv = false;
int n, k;
vector<vector<int>> v;
 
vector<int> get_comp(vector<int> a, vector<int> b) {
	vector<int> res(k);
	for (int i = 0; i < k; i++)
		res[i] = (6 - (a[i] + b[i])) % 3;
	return res;
}
 
void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &vec : v) {
		vec.resize(k);
		for (auto &i : vec)
			cin >> i;
	}
	map<vector<int>, int> cnt;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			auto comp = get_comp(v[i], v[j]);
			cnt[comp]++;
		}
	}
	ll ans = 0;
	for (auto vec : v) {
		ans += (ll)cnt[vec] * (cnt[vec] - 1) / 2;
	}
	cout << ans << '\n';
}
 
int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();
 
	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}