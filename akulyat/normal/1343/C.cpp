#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
bool viv = false;
vector<ll> v;

void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<vector<ll>> vv;
	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i] * v[i - 1] < 0) 
			vv.push_back({});
		vv.back().push_back(v[i]);
	}

	ll ans = 0;
	for (int i = 0; i < vv.size(); i++) {
		ans += *max_element(vv[i].begin(), vv[i].end());
	}
	cout << ans << '\n';
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}