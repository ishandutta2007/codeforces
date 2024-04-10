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
bool viv = false;
vector<ll> v;

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<ll> p;
	p.push_back(0);	
	for (auto i : v)
		p.push_back(p.back() + i);


	ll l = 0;
	ll r = 0;
	set<ll> s;
	s.insert(p[0]);
	ll ans = 0;
	while (r < n) {
		while (s.count(p[r + 1])) {
			s.erase(p[l]), l++;
		}
		r++;
		s.insert(p[r]);
		ans += r - l;
	}
	cout << ans << endl;
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}