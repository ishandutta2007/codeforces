#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

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
vector<ll> v;
bool viv = false;

ll min(ll a, ll b, ll c) {
	return min(a, min(b, c));
}
ll max(ll a, ll b, ll c) {
	return max(a, max(b, c));
}

void solve() {
	v.clear();
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;

	vector<ll> ans;
	ans.push_back(0);
	for (int i = 1; i < n - 1; i++)
		if (max(v[i - 1], v[i], v[i + 1]) == v[i] || min(v[i - 1], v[i], v[i + 1]) == v[i])
			ans.push_back(i);
	ans.push_back(n - 1);

	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << v[i] + 1 << ' ';
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