#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<array<int, 3>> moves;
	for (int i = 0; i < n; ++i) {
		int loc = i;
		for (int j = i; j < n; ++j) {
			if (a[j] < a[loc]) {
				loc = j;
			}
		}
		if (i != loc) {
			moves.push_back({i + 1, loc + 1, loc - i});
		}
		rotate(a.begin() + i, a.begin() + loc, a.begin() + loc + 1);
	}
	cout << moves.size() << '\n';
	for (auto [x, y, z] : moves) {
		cout << x << ' ' << y << ' ' << z << '\n';
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