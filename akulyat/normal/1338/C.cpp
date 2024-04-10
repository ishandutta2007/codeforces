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
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n;
bool viv = false;
ll change[3][4] = {{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}};

void solve() {
	ll n, fn;
	int st = 0;
	cin >> n;
	fn = n;
	for (int i = 0; i < 54; i += 2)
		if (fn >>= 2)
			st = i + 2;
	ll delt = (n - (1ll << st));
	ll ans = (1 + delt % 3) * (1ll << st);
	int modl = delt % 3;
	ll rest = delt / 3;
	for (int i = 0; i < st; i += 2) 
		ans += change[modl][rest & 3] << i, rest >>= 2;
	cout << ans << '\n';
}


int main() {
	// viv = true;
	// srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; 
	cin >> t;
	while (t--) 
		solve();

	return 0;
}