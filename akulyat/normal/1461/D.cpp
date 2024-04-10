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

ll n, q;
vector<ll> v;
bool viv = false;
set<ll> s;

void work(vector<ll> v) {
	if (viv) {
		cout << "work: ";
		for (auto i : v)
			cout << i << ' ';
		cout << '\n';
	}
	ll sum = 0;
	ll mx = v[0], mn = v[0];
	for (auto i : v)
		mx = max(mx, i), mn = min(mn, i), sum += i;
	s.insert(sum);
	ll md = mx + mn >> 1;
	vector<ll> a, b;
	for (auto i : v)
		if (i <= md)
			a.push_back(i);
		else
			b.push_back(i);
	if (a.empty() || b.empty())
		return;
	work(a);
	work(b);
}

void solve() {
	cin >> n >> q; 
	v.resize(n);
	s.clear();
	for (auto &i : v)
		cin >> i;
	work(v);
	while (q--) {
		ll val;
		cin >> val;
		if (s.find(val) != s.end())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
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