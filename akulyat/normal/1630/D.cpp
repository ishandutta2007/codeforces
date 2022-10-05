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
int n, m;
vector<ll> v;
vector<int> b;

void solve() {
	cin >> n >> m;
	v.resize(n);
	b.resize(m);
	for (auto &i : v)
		cin >> i;
	for (auto &i : b)
		cin >> i;

	int val = b[0];
	for (auto i : b)
		val = __gcd(val, i);

	vector<ll> g(2);
	for (int i = 0; i < val; i++) {
		vector<ll> vec;
		int cnt = 0;
		for (int j = i; j < n; j += val) {
			vec.push_back(abs(v[j]));
			cnt += v[j] < 0;
		}
		ll value = inf;
		for (auto val : vec)
			value = min(value, val);

		g[cnt % 2] += value;
	}
	ll dif = min(g[0], g[1]);

	ll ans = 0;
	for (auto i : v)
		ans += abs(i);
	ans -= 2 * dif;
	cout << ans << '\n';
	if (viv)
		cout << "\tdif = " << dif << endl;
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