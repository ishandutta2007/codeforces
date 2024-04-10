#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e17 + 10;
const ll MOD = 1e9 + 7;
const int M = 21;
const int N = 1e6 + 10;



void solve() {
	ll m, d, w;
	cin >> m >> d >> w;
	ll t = min(m, d);
	ll g1 = __gcd(d - 1, w);
	ll w1 = w / g1;
	ll maxcoef = t / w1;
	cout << maxcoef * t - w1 * (maxcoef * (maxcoef + 1)) / 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();	
	}
}