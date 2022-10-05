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
vector<ll> v;
vector<vector<int>> e;
multiset<ll> s;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	e.assign(n, {});
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}	
	s.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < e[i].size(); j++) 
			s.insert(-v[i]);
	}
	ll ans = 0;
	for (auto i : v)
		ans += i;
	cout << ans << ' ';
	for (int i = 2; i < n; i++) {
		auto z = s.begin();
		ll add = *z;
		s.erase(z);
		ans -= add;
		cout << ans << ' ';
	}
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