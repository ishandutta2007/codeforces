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

ll n, k;
vector<ll> p;
bool viv = false;

vector<ll> erat(ll n) {
	vector<bool> pr(n + 1, true);
	vector<ll> res;
	for (ll i = 2; i < n; i++) {
		if (pr[i])
			res.push_back(i);
		for (ll j = i * i; j < n; j += i)
			pr[j] = false;		
	}
	return res;
}


ll phi(ll v) {
	ll val = 1;
	for (auto i : p) {
		int cnt = 0;
		while (v % i == 0)
			v /= i, cnt++;
		while (cnt > 1)
			val *= i, cnt--;
		while (cnt > 0)
			val *= (i - 1), cnt--;
	}
	if (v > 1)
		val *= (v - 1);
	return val;
}

void solve() {
	p = erat(ml + 10);
	cin >> n >> k;
	k++;
	k /= 2;
	if (viv)
		cout << "now " << n << endl;
	while (k && n > 1) {
		n = phi(n), k--;
		if (viv)
			cout << "now " << n << endl;
	}
	cout << n % mod << '\n';

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