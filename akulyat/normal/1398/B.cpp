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
	string s;
	cin >> s;
	n = s.size();
	vector<ll> v;
	v.resize(s.size());
	for (int i = 0; i < n; i++)
		v[i] = (s[i] == '1');
	for (int i = 1; i < n; i++)
		if (v[i])
			v[i] += v[i - 1];
	v.push_back(0);
	vector<ll> sz;
	for (int i = 1; i <= n; i++)
		if (v[i] == 0 && v[i - 1] != 0)
			sz.push_back(v[i - 1]);
	sort(sz.rbegin(), sz.rend());
	ll ans = 0;
	for (int i = 0; i < sz.size(); i += 2)
		ans += sz[i];
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