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
string s;


void solve() {
	cin >> n;
	if (n <= 3) {
		cout << -1 << '\n';
		return;
	}
	ll sz = 4;
	while ((n - sz) % 4)
		sz++;
	map<ll, vector<ll>> st;
	st[4] = {2, 4, 1, 3};
	st[5] = {2, 4, 1, 3, 5};
	st[6] = {1, 4, 2, 6, 3, 5};
	st[7] = {2, 4, 1, 5, 7, 3, 6};

	vector<ll> ans;
	for (auto i : st[sz])
		ans.push_back(i);
	ll str = sz + 1;
	while (str <= n) {
		for (int i = 0; i < 4; i++)
			ans.push_back(str - 1 + st[4][i]);
		str += 4;
	}
	for (auto i : ans)
		cout << i << ' ';
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