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

ll n, m;
vector<ll> v1, v2, v;
bool viv = false;


void solve() {
	cin >> n >> m;
	v1.clear(), v2.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		sum += v[i];
		if (tp == 1)
			v1.push_back(v[i]);
		else
			v2.push_back(v[i]);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	ll have = 0;
	ll lans = 0;
	ll ans = inf;
	for (auto i : v1)
		have += i, lans++;

	while (have < m && v2.size())
		have += v2.back(), lans += 2, v2.pop_back();
	if (have >= m)
		ans = min(ans, lans);

	for (auto i : v1) {
		have -= i;
		lans--;
		while (have < m && v2.size())
			have += v2.back(), lans += 2, v2.pop_back();
		if (have >= m)
			ans = min(ans, lans);
	}

	if (ans == inf)
		ans = -1;
	cout << ans << '\n';
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