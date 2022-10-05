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

ll n;
bool viv = false;
vector<ll> v;

void solve() {
	cin >> n;
	ll k = n;
	ll st = 1;
	vector<ll> a;
	if (viv)
		cout << "Left " << k << '\n';
	while (k) {
		ll v = min(k, st);
		a.push_back(v);
		k -= v;
		st *= 2;
		if (viv)
			cout << "Left " << k << '\n';
	}
	if (viv) {
		for (auto i : a)
			cout << i << ' ';
		cout << endl;
	}
	if (a.size() >= 2) {
		auto sz = a.size();
		ll b1 = a[sz - 2];
		ll b2 = a[sz - 1];
		if (b1 > b2) {
			ll h = b1 + b2 >> 1;
			ll sh = b1 + b2 - h;
			a.pop_back();
			a.pop_back();
			a.push_back(h);
			a.push_back(sh);
		}
	}
	vector<ll> ans;
	for (int i = 1; i < a.size(); i++)
		ans.push_back(a[i] - a[i - 1]);
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
	if (viv)
		cout << '\n';
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