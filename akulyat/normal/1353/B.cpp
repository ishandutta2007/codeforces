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


void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a, b;
	a.resize(n);
	b.resize(n);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;

	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());
	k = min(n, k);

	vector<ll> c;
	for (int i = 0; i < k; i++)
		c.push_back(a.back()), a.pop_back();
	for (int i = 0; i < k; i++)
		c.push_back(b.back()), b.pop_back();
	sort(c.rbegin(), c.rend());
	ll ans  = 0;
	for (auto i : a)
		ans += i;
	for (int i = 0; i < k; i++)
		ans += c[i];
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