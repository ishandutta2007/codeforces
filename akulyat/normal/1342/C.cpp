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
	ll a, b, q;
	cin >> a >> b >> q;
	vector<ll> add(a * b, 0);
	ll sum = 0;
	for (int i = 0; i < a * b; i++) {
		ll z1 = (i % a) % b;
		ll z2 = (i % b) % a;
		if (z1 != z2)
			add[i]++, sum++;
	}
	for (int i = 0; i < a * b; i++) 
		add.push_back(add[i]);
	vector<ll> p;
	p.push_back(0);
	for (auto i : add)
		p.push_back(p.back() + i);
	while (q--) {
		ll l, r;
		cin >> l >> r;
		ll len = r - l + 1;	
		len /= (a *  b);
		ll res = 0;
		res += len * sum;
		r -= len * (a * b);
		ll need = r - l + 1;
		l %= (a * b);
		res += p[l + need] - p[l];
		cout << res << ' ';
	}
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