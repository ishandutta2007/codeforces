#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e14;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

ll a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n, greater<ll>());
	cout << accumulate(a, a + k + 1, 0ll) << "\n";

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