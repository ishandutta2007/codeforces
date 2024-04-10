#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<array<int, 2>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i][1] >> v[i][0];
	}
	auto check = [&](int num) {
		int take = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (v[i][1] >= take && v[i][0] >= num - take - 1) {
				++take;
			}
		}
		return take >= num;
	};
	int lo = 0; 
	int hi = n;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (check(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	if (check(hi)) {
		cout << hi << '\n';
	} else {
		cout << lo << '\n';
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