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


ll n, x;
bool viv = false;
vector<ll> v;

void solve() {
	cin >> n >> x;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.rbegin(), v.rend());
	int ans = 0;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		if (x * (i + 1) <= sum)
			ans = i + 1;
	}
	cout << ans << '\n';
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