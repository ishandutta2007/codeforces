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

ll n, q;
vector<ll> v;
set<ll> s;
multiset<ll> dif;
bool viv = false;

ll get_len() {
	if (s.size() == 2)
		return 0;
	auto st = s.find(0);
	auto fn = s.find(mod);
	st++;
	fn--;

	return((*fn) - (*st));
}

ll get_x() {
	if (s.size() <= 3)
		return 0;
	auto z = dif.rbegin();
	return *z;
}

void add(ll pl) {
	s.insert(pl);
	auto z = s.find(pl);
	auto pr = z, nx = z;
	pr--;
	nx++;

	ll pl_pr = *pr;
	ll pl_nx = *nx;

	if (pl_pr != 0 && pl_nx != mod) {
		dif.erase(dif.find(pl_nx - pl_pr));
	}
	if (pl_pr != 0) {
		dif.insert(pl - pl_pr);
	}
	if (pl_nx != mod) {
		dif.insert(pl_nx - pl);
	}

	if (viv) {
		for (auto i : dif)
			cout << i << ' ';
		cout << endl;
	}
}

void er(ll pl) {
	auto z = s.find(pl);
	auto pr = z, nx = z;
	pr--;
	nx++;

	ll pl_pr = *pr;
	ll pl_nx = *nx;

	if (pl_pr != 0 && pl_nx != mod) {
		dif.insert(pl_nx - pl_pr);
	}
	if (pl_pr != 0) {
		dif.erase(dif.find(pl - pl_pr));
	}
	if (pl_nx != mod) {
		dif.erase(dif.find(pl_nx - pl));
	}

	s.erase(pl);	
}

void solve() {
	cin >> n >> q;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	s.clear();
	s.insert(0);
	s.insert(mod);

	for (auto i : v)
		add(i);

	ll l = get_len();
	ll x = get_x();

	if (viv)
		cout << l << " " << x << ": ";

	cout << l - x << '\n';

	while (q--) {
		ll t, pl;
		cin >> t >> pl;
		if (t) {
			add(pl);
		} else
			er(pl);

		ll l = get_len();
		ll x = get_x();
	
		if (viv)
			cout << l << " " << x << ": ";
	
		cout << l - x << '\n';
	}


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