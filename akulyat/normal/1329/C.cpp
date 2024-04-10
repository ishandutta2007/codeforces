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


ll n, p1, p2, s1, s2;
vector<ll> v, ans;
vector<pll> d;
bool viv = false;

void f(ll i) {
	if (v[2 * i] == 0 && v[2 * i + 1] == 0)
		return void (d.push_back({i, 0}));
	if (v[2 * i] > v[2 * i + 1]) {
		d.push_back({i, v[2 * i]});
		f(2 * i);
	} else {
		d.push_back({i, v[2 * i + 1]});
		f(2 * i + 1);
	}
}

void work(ll pl) {
	d.clear();
	if (viv) {
		cout << "In " << pl << endl;
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
	if (pl > s2)
		return;
	f(pl);
	if (viv) {
		for (auto p : d) {
			cout << p.F << ' ' << p.S << "; ";
		}
		cout << endl << endl;
	}

	for (auto p : d) 
		if (p.F <= s2 && p.S == 0)
			return void(work(pl + 1));
	ans.push_back(pl);
	for (auto p : d)
		v[p.F] = p.S;
	work(pl);
}

void solve() {
	v.clear();
	d.clear();
	ans.clear();
	cin >> p1 >> p2;
	s1 = (1 << p1) - 1;
	s2 = (1 << p2) - 1;
	v.resize(2 * s1 + 2);
	for (int i = 0; i < s1; i++) {
		cin >> v[i + 1];
	}

	work(1);

	ll sum = 0;
	for (auto i : v)
		sum += i;
	cout << sum << '\n';
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';

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