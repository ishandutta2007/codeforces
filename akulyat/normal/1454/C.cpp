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
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	bool one = true;
	for (int i = 1; i < n; i++)
		if (v[i] != v[i - 1])
			one = false;
	if (one) {
		cout << "0\n";
		return;
	}
	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		if (mp[v[i]].empty())
			mp[v[i]].push_back(-1);
		if (mp[v[i]].back() + 1 == i)
			mp[v[i]].back()++;
		else
			mp[v[i]].push_back(i);
	}
	for (auto &p : mp) {
		if (p.S.back() + 1 == n)
			p.S.back()++;
		else
			p.S.push_back(n);
	}
	ll ans = n;
	for (auto p : mp)
		ans = min(ans, (ll)p.S.size());
	ans--;
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