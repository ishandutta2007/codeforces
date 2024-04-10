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

ll n;
vector<ll> a, b;
bool viv = false;

ll get(vector<ll> v) {
	ll ans = 0;
	for (int i = 0; i < 6; i++) {
		ll add = min(v[i], v[(i + 1) % 6]);
		v[i] -= add;
		v[(i + 1) % 6] -= add;
		ans += add;
	}
	return ans;
}

ll solver(vector<ll> vec) {
	for (int i = 0; i < 6; i++)
		vec.push_back(vec[i]);
	ll ans = 0;
	for (int i = 0; i < 6; i++) {
		vector<ll> v;
		for (int j = i; j < i + 6; j++)
			v.push_back(vec[j]);
		ll lans = get(v);
		// cout << lans << '\n';
		ans = max(ans, lans);
	}
	return ans;
}

void solve() {
	cin >> n;
	a.resize(3);
	b.resize(3);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;
	for (int i = 0; i < 3; i++) 
		a.push_back(a[i]);
	for (int i = 0; i < 3; i++) 
		b.push_back(b[i]);
	ll ans0 = 0, ans1 = 0;
	for (int i = 0; i < 3; i++) {
		ans0 += min(a[i], b[i + 1]);
	}
	vector<ll> vec;
	for (int i = 0; i < 3; i++) {
		vec.push_back(a[i]);
		vec.push_back(b[i]);
	}
	ans1 = n - solver(vec);
	cout << ans1 << ' ' << ans0 << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}