#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 


ll n;
vector<pll> a, b;
bool viv = false;

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto &i : a)
		cin >> i.F;
	for (auto &i : b)
		cin >> i.F;

	for (int i = 0; i < n; i++)
		a[i].S = i, b[i].S = i;

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	vector<ll> ans(n, -1);
	for (int i = 0; i < n; i++)
		ans[b[i].S] = a[i].F;
	for (auto &i : ans)
		cout << i << ' ';
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}