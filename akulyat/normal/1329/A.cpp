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


ll n, l;
vector<ll> v;
bool viv = false;

void bad() {
	cout << -1;
	exit(0);
}

void solve() {
	cin >> l >> n;
	v.resize(n);
	ll sum = 0;
	for (auto &i : v)
		cin >> i, sum += i;
	if (sum < l)
		bad();
	for (int i = 0; i < v.size(); i++) 
		if (i + v[i] > l)
			bad();

	ll las = l;
	vector<ll> ans;
	for (int i = v.size() - 1; i >= 0; i--) {
		ll me = max((ll)i, las - v[i]);
		ans.push_back(me);
		las = me;
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i + 1 << ' ';
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