#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	array<int, 2> a, b, f;
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];

	cin >> f[0] >> f[1];
	if (a[0] == b[0] && a[0] == f[0]) {
		if (a[1] > b[1]) {
			swap(a, b);
		}
		if (a[1] < f[1] && f[1] < b[1]) {
			cout << abs(a[1] - b[1]) + 2 << '\n';
			return;
		} 
	} else if (a[1] == b[1] && a[1] == f[1]) {
		if (a[0] > b[0]) {
			swap(a, b);
		}
		if (a[0] < f[0] && f[0] < b[0]) {
			cout << abs(a[0] - b[0]) + 2 << '\n';
			return;
		}
	}
	cout << abs(a[0] - b[0]) + abs(a[1] - b[1]) << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}