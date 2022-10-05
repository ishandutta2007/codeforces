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


ll n, m, k;
vector<pll> s, f;
vector<ll> mv;
bool viv = false;

void mov(ll num, ll w, bool add = false) {
	if (add)
		mv.push_back(w);
	if (w == 0) {
		if (s[num].F > 0)
			s[num].F--;
		return;
	}
	if (w == 1) {
		if (s[num].S < m - 1)
			s[num].S++;
		return;
	}
	if (w == 2) {
		if (s[num].F < n - 1)
			s[num].F++;
		return;
	}
	if (w == 3) {
		if (s[num].S > 0)
			s[num].S--;
		return;
	}
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		s.push_back({a, b});
	}
	for (int i = 0; i < k; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		f.push_back({a, b});
	}

	for (int i = 0; i < n - 1; i++)
		mv.push_back(0);
	for (int i = 0; i < m - 1; i++)
		mv.push_back(3);
	for (int i = 0; i < m; i++) {
		if (i & 1) {
			for (int j = 0; j < n - 1; j++)
				mv.push_back(0);
		} else {
			for (int j = 0; j < n - 1; j++)
				mv.push_back(2);			
		}
		mv.push_back(1);
	}

	cout << mv.size() << endl;
	for (auto i : mv) {
		if (i == 0)
			cout << "U";
		if (i == 1)
			cout << "R";
		if (i == 2)
			cout << "D";
		if (i == 3)
			cout << "L";
	}
}



int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();

	return 0;
}