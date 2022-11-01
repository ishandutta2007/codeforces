#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

void solve() {
	ll x, y, k;
	cin >> x >> y >> k;
	cout << k + (k * y + k - 1 + x - 2) / (x - 1) << "\n";	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();	
	}
}