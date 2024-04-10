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
vector<ll> v;

void solve() {
	cin >> n;
	if (n % 4 == 2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	ll k = n / 2;
	for (int i = 0; i < k; i++) {
		cout << 4 + 4 * i << ' ';
	}
	for (int i = 0; i < k; i++) {
		ll ans = 4 + 4 * i;
		if (i & 1)
			ans++;
		else
			ans--;
		cout << ans << ' ';
	}
	cout << '\n';
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