#include <bits/stdc++.h>

using namespace std;

const int L = 20;
const int N = 2e5 + 5;

int p[L][N];

void pcp() {
	for (int j = 0; j < L; ++j) {
		for (int i = 1; i < N; ++i) {
			int v = 0;
			if (i & (1 << j)) {
				v = 1;
			}
			p[j][i] = v + p[j][i - 1];
		}
	}
}

void solve_case(int tc = 0) {
	const int INF = 1e9;
	int l, r;
	cin >> l >> r;
	int ans = INF;
	for (int d = 0; d < L; ++d) {
		ans = min(ans, r - l + 1 - p[d][r] + p[d][l - 1]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	pcp();
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}