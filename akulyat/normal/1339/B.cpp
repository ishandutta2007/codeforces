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
	sort(v.begin(), v.end());
	ll r = n / 2, l = r - 1;
	vector<ll> ans;
	while (l >= 0 || r <= n - 1) {
		if (r <= n - 1)
			ans.push_back(v[r]), r++;
		if (l >= 0)
			ans.push_back(v[l]), l--;
	}
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}