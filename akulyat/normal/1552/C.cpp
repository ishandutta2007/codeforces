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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<pii> v;
bool viv = false;

bool bad(int i, int j) {
	int a = v[i].F;
	int b = v[i].S;
	int c = v[j].F;
	int d = v[j].S;

	b -= a;
	c -= a;
	d -= a;
	b %= 2 * n;
	c %= 2 * n;
	d %= 2 * n;

	b += 2 * n;
	c += 2 * n;
	d += 2 * n;
	b %= 2 * n;
	c %= 2 * n;
	d %= 2 * n;

	if ((d < b) ^ (c < b))
		return false;
	return true;
}


void solve() {
	int k;
	cin >> n >> k;
	v.resize(k);
	for (auto &p : v)
		cin >> p.F >> p.S, p.F--, p.S--;

	vector<bool> emp(2 * n, true);
	for (auto p : v)
		emp[p.F] = emp[p.S] = false;

	vector<int> f;
	for (int i = 0; i < 2 * n; i++)
		if (emp[i])
			f.push_back(i);

	int l = n - k;

	for (int i = 0; i < l; i++)
		v.push_back({f[i], f[i + l]});

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans += !bad(i, j);
	cout << ans << '\n';

	// ll ans = l * (l - 1) / 2;

	// for (int i = 0; i < k; i++) {
	// 	int d = abs(v[i].F - v[i].S);
	// 	d = min(d, 2 * n - d);
	// 	ans += d - 1;
	// }

	// for (int i = 0; i < k; i++) {
	// 	for (int j = i + 1; j < k; j++) {
	// 		if (!bad(i, j))
	// 			ans--;
	// 		// ans--;
	// 	}
	// }
	// cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}