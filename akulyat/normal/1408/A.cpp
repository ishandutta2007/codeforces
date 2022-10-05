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
vector<ll> a, b, c, ans;
bool viv = false;


void solve() {
	cin >> n;
	a.resize(n);	
	b.resize(n);	
	c.resize(n);	
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;
	for (auto &i : c)
		cin >> i;

	ans.clear();
	ans.resize(n, -1);
	for (int i = 0; i < n; i++) {
		ans[i] = a[i];
		if (ans[i] == ans[(i - 1 + n) % n] || ans[i] == ans[(i + 1) % n])
			ans[i] = b[i];
		if (ans[i] == ans[(i - 1 + n) % n] || ans[i] == ans[(i + 1) % n])
			ans[i] = c[i];
	}
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
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