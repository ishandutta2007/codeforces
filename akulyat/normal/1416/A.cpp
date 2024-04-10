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
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	map<ll, vector<ll>> mp;
	vector<pll> pr;
	for (int i = 0; i < n; i++)
		mp[v[i]].push_back(i);
	for (auto p : mp) {
		vector<ll> vec;
		vec.push_back(-1);
		for (auto i : p.S)
			vec.push_back(i);
		vec.push_back(n);
		ll mx = -1;
		for (int i = 1; i < vec.size(); i++)
			mx = max(mx, vec[i] - vec[i - 1]);
		pll add = {mx, p.F};
		pr.push_back(add);
	}
	vector<ll> ans(n + 1, inf);
	sort(pr.begin(), pr.end());
	for (auto p : pr) {
		// cout << p.F << ' ' << p.S << endl;
		ans[p.F] = min(ans[p.F], p.S);
	}
	for (int i = 1; i < ans.size(); i++)
		ans[i] = min(ans[i], ans[i - 1]);
	for (auto &i : ans)
		if (i == inf)
			i = -1;
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
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