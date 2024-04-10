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

ll n, k;
bool viv = false;
vector<ll> v;
set<ll> ss;

ll cnt(vector<ll> v) {
	set<ll> s;
	for (auto &i : v)
		s.insert(i);
	ss = s;
	return s.size();
}

void solve() {
	cin >> n >> k;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	if (cnt(v) > k) {
		cout << "-1\n";
	} else {
		vector<ll> vv;
		for (auto i : ss)
			vv.push_back(i);
		while (vv.size() < k)
			vv.push_back(v[0]);
		cout << 100 * vv.size() << '\n';
		for (int i = 0; i < 100; i++) {
			for (auto i : vv)
				cout << i << ' ';
		}
		
		cout << '\n';
	}
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