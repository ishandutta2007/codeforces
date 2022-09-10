#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)

using ll = long long;
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	int R = 0, W = 0;
	rep(_, 1, m) {
		int r, w;
		cin >> r >> w;
		R = max(R, r);
		W = max(W, w);
	}

	if (R + W > n) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		rep(i, 1, n) cout << (i <= R ? 'R' : 'W');
		cout << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}