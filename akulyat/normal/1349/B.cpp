#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

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

ll n;
bool viv = false;


void solve() {
	ll n, k;
	vector<ll> v;
	cin >> n >> k;
	v.resize(n);
	if (n == 1) {
		ll val;
		cin >> val;
		if (val == k)
			cout << "yes\n";
		else
			cout << "no\n";
		return;
	} 

	bool bad = true;
	for (auto &i : v) {
		cin >> i;	
		if (i == k)
			bad = false;
		if (i >= k)
			i = 1;
		else {
			i = -1;
		}
	}

	if (bad) {
		cout << "no\n";
		return;
	}

	vector<ll> p;
	p.push_back(0);
	for (auto i : v)
	p.push_back(p.back() + i);

	ll mn = 0;
	for (int i = 2; i < p.size(); i++) {
		mn = min(mn, p[i - 2]);
		if (mn < p[i]) {
			cout << "yes\n";
			return;
		}
	}	
	cout << "no\n";

}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}