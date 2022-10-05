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
vector<ll> a, b;

void solve() {
	cin >> n;
	a.clear();
	b.clear();
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i] >> b[i];

	for (int i = 0; i < n; i++)
		a.push_back(a[i]);
	for (int i = 0; i < n; i++)
		b.push_back(b[i]);

	vector<ll> v;
	for (int i = 0; i < n; i++) {
		v.push_back(min(b[i], a[i + 1]));
	}
	sort(v.rbegin(), v.rend());
	v.pop_back();

	ll ans = 0;
	for (auto i : a)
		ans += i;
	ans /= 2;

	for (auto i : v)
		ans -= i;

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