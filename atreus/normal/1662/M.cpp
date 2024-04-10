#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 77;

void solve() {
	int n, m;
	cin >> n >> m;
	int maxR = 0, maxW = 0;
	for (int i = 0; i < m; i++) {
		int r, w;
		cin >> r >> w;
		maxR = max(maxR, r);
		maxW = max(maxW, w);
	}
	if (maxR + maxW > n) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (int i = 0; i < n; i++)
		cout << (i < maxR ? 'R' : 'W');
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}