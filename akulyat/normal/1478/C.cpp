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
	n *= 2;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	map<ll, ll> mp;
	for (auto i : v)
		mp[i]++;

	for (auto p : mp)
		if (p.S != 2 || (p.F & 1)) {
			cout << "NO\n";
			return;
		}
	vector<ll> m;
	for (auto p : mp)
		m.push_back(p.F);
	n = m.size();

	vector<ll> dif(n, 0);
	ll sum = 0;
	for (int i = 1; i < n; i++) {
		if ((m[i] - m[i - 1]) % (2 * i)) {
			cout << "NO\n";
			return;
		}
		sum += (m[i] - m[i - 1]) / (2 * i);
		dif[i] = sum;
	}
	ll S = m[0] / 2;
	for (auto i : dif)
		S -= i;
	if (S <= 0 || S % n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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