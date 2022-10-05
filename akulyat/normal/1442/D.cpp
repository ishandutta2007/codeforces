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

ll n, k, ans;
vector<pll> sums;
vector<vector<ll>> v;
bool viv = false;

void add(vector<ll> &can, pll p) {
	for (int i = k; i >= p.F; i--)
		can[i] = max(can[i], can[i - p.F] + p.S);
}

void work(ll l, ll r, vector<ll> &can) {
	if (l + 1 == r) {
		ll sum = 0;
		for (int i = 0; i <= min(k, sums[l].F); i++) {
			if (i)
				sum += v[l][i - 1];
			ans = max(ans, sum + can[k - i]);
		}
		return;
	}
	auto canl = can;
	auto canr = can;

	int m = l + r >> 1;
	for (int i = m; i < r; i++)
		add(canl, sums[i]);
	for (int i = l; i < m; i++)
		add(canr, sums[i]);
	work(l, m, canl);
	work(m, r, canr);
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &l : v) {
		int sz;
		cin >> sz;
		ll sum = 0;
		l.resize(sz);
		for (auto &i : l)
			cin >> i, sum += i;
		sums.push_back({sz, sum});
	}
	ans = 0;
	vector<ll> can(k + 1, -inf);
	can[0] = 0;
	work(0, n, can);

	cout << ans << '\n';
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