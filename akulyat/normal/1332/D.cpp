#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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


ll n, k;
bool viv = false;
vector<ll> v;

void solve() {
	cin >> k;
	int st = 1;
	ll val = 100 * kk;
	// ll val = 8
	while (st < val)
		st <<= 1;

//	st <<= 1;

	vector<vector<ll>> ans = {{st + k, st}, {k, st + k}, {st, k}};
	cout << 3 << ' ' << 2 << '\n';
	for (auto l : ans) {
		for (auto i : l)
			cout << i << ' ';
		cout << '\n';
	}
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