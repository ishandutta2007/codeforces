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
	int h = n / 2;
	vector<ll> p(n, 0);
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < h - 1; i++)
		swap(p[i], p[h - 1]);
	for (int i = n - 1; i > h; i--)
		swap(p[i], p[h]);
	swap(p[0], p[n - 1]);
	
	vector<pll> a;
	for (int i = h - 1; i > 0; i--) 
		a.push_back({i, n - 1});
	for (int i = h; i < n - 1; i++) 
		a.push_back({i, 0});
	a.push_back({0, n - 1});

	ll ans = 0;
	for (auto p : a)
		ans += (p.F - p.S) * (p.F - p.S);
	cout << ans << '\n';
	for (auto i : p)
		cout << i + 1 << ' ';
	cout << '\n';
	cout << n - 1 << '\n';
	for (auto p : a)
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}