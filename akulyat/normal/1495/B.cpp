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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<int> p;
	for (int i = 1; i < n; i++)
		p.push_back(v[i] > v[i - 1]);
	vector<int> same(p.size(), 1);
	for (int i = 1; i < p.size(); i++)
		if (p[i] == p[i - 1])
			same[i] += same[i - 1];
	for (auto &i : same)
		i++;

	vector<int> c;
	if (v[0] > v[1])
		c.push_back(1);
	same.push_back(0);
	for (int i = 0; i < same.size() - 1; i++)
		if (same[i] >= same[i + 1])
			c.push_back(same[i]);
	if (c.size() & 1)
		c.push_back(1);
	int mx = 0;
	for (auto i : c)
		mx = max(mx, i);
	int cnt = 0;
	for (auto i : c)
		cnt += (i == mx);
	if (viv) {
		for (auto i : c)
			cout << i << ' ';
		cout << endl;
	}
	int ans = 0;
	for (int i = 0; i < c.size(); i += 2) {
		int l = c[i];
		int r = c[i + 1];
		int lcnt = cnt;
		lcnt -= (l == mx);
		lcnt -= (r == mx);
		if (!lcnt) {
			if (abs(l - r) <= 0 && (mx & 1))
				ans++;
		}
	}
	cout << ans << '\n';
}	

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}