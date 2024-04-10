#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;


void solve() {
	int n, x, m;
	cin >> n >> x >> m;
	int l = x, r = x;
	for (int i = 0; i < m; ++i) {
		int li, ri;
		cin >> li >> ri;
		if (li > r || ri < l) continue;
		l = min(l, li);
		r = max(r, ri);
	}
	cout << r - l + 1 << "\n";
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