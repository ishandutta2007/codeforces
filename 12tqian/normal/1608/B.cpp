#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n, a, b;
	cin >> n >> a >> b;
	if (a + b > n - 2 || abs(a - b) > 1) {
		cout << -1 << '\n';
		return;
	} else {
		bool flip = false;
		bool eq = a == b;
		if (a < b) {
			swap(a, b);
			flip = true;
		}
		vector<int> p;
		int l = 0;
		int r = 1;
		while (a) {
			if (p.empty()) {
				p.push_back(l--);
				p.push_back(r++);
				p.push_back(l--);
			} else {
				p.push_back(l--);
			}
			--a;
			if (b) {
				--b;
				p.push_back(r++);
			}
		}
		if (eq) {
			while ((int)p.size() < n) {
				p.push_back(r++);
			} 
		} else {
			while ((int)p.size() < n) {
				p.push_back(l--);
			}
		}
		auto v = p;
		sort(v.begin(), v.end());
		for (int i = 0; i < n; ++i) {
			int x = lower_bound(v.begin(), v.end(), p[i]) - v.begin() + 1;
			if (flip) {
				x = n + 1 - x;
			}
			cout << x << ' ';
		}
		cout << '\n';
	}
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