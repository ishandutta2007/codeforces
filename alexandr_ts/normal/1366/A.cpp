#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;


void solve() {
	int a, b;
	cin >> a >> b;
	int ans = (a + b) / 3;
	ans = min(ans, a);
	ans = min(ans, b);
	cout << ans << "\n";
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