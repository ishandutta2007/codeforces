#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	map<ll, ll> cnt;
	for (auto i : v)
		cnt[i]++;

	vector<ll> tos;
	for (auto p : cnt)
		tos.push_back(p.S);

	sort(tos.rbegin(), tos.rend());

	ll mx = tos[0];
	ll c = 0;
	for (auto i : tos)
		c += (mx == i);

	int ans = -1;
	for (int i = 0; i < n; i++) {
		ll val = (n + i) / (i + 1);
		ll dif =  (n % (i + 1));
		if (dif == 0)
			dif = i + 1;
		if (val > mx || val >= mx && dif >= c)
			ans = max(ans, i);
	}
	cout << ans << '\n';
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