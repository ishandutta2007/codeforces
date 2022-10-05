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

ll make(ll val, ll x) {
	return (val + x - 1) / x;
}

void solve() {
	ll x, sum = 0;
	cin >> n >> x;
	v.resize(n);
	for (auto &i : v)
		cin >> i, sum += i;
	vector<ll> all;
	all.push_back(make(sum, x));
	all.push_back(0);
	for (auto i : v)
		all.back() += make(i, x);
	sort(all.begin(), all.end());
	for (auto i : all)
		cout << i << ' ';
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