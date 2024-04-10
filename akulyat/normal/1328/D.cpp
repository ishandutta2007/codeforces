#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

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
vector<ll> v;
bool viv = false;

void ans1(ll n) {
	cout << 1 << '\n';
	for (int i = 0; i < n; i++)
		cout << 1 << ' ';
	cout << '\n';
}

void ev(ll n) {
	cout << 2 << '\n';
	for (int i = 0; i < n; i++)
		cout << 1 + (i & 1) << ' ';
	cout << '\n';
}

void evs(ll n, ll s) {
	cout << 2 << '\n';
	vector<ll> ans(n, 0);
	ll now = 0;
	for (int i = 0; i < n; i++) {
		ans[(s + i) % n] = 1 + now;
		now ^= 1;
	}
	for (auto i : ans)
		cout << i << ' ';	
	cout << '\n';
}

void ans3(ll n) {
	cout << 3 << '\n';
	cout << 3 << ' ';
	for (int i = 1; i < n; i++)
		cout << 1 + (i & 1) << ' ';
	cout << '\n';
}

void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	bool dif = false;
	for (int i = 0; i < n; i++)
		if (v[i] != v[(i + 1) % n])
			dif = true;
	if (!dif)
		return void(ans1(n));

	if (!(n & 1))
		return void(ev(n));

	for (int i = 0; i < n; i++) {
		if (v[i] == v[(i + 1) % n])
			return void(evs(n, (i + 1) % n));
	}
	ans3(n);
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}