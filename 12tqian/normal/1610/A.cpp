#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n, m;
	cin >> n >> m;
	if (n < m) {
		swap(n, m);
	}
	if (n == m && m == 1) {
		cout << 0 << '\n';
	} else if (m == 1) {
		cout << 1 << '\n';
	} else {
		cout << 2 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}