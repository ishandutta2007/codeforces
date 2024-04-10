#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n, k;
bool viv = false;
vector<ll> v, c;

void solve() {
	cin >> n >> k;
	v.resize(n);
	c.resize(k);
	for (auto &i : v)
		cin >> i;
	for (auto &i : c)
		cin >> i;

	sort(v.rbegin(), v.rend());
	vector<ll> have(k, 0);
	for (auto i : v)
		have[i - 1]++;
	for (int i = (ll)have.size() - 2; i >= 0; i--)
		have[i] += have[i + 1];

	ll need = 0;
	for (int i = 0; i < k; i++) {
		need = max(need, (have[i] + c[i] - 1) / c[i]);
	}

	vector<vector<ll>> ans(need);
	for (int i = 0; i < n; i++)
		ans[i % ans.size()].push_back(v[i]);

	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i.size() << ' ';
		for (auto j : i)
			cout << j << ' ';
		cout << '\n';
	}

}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}