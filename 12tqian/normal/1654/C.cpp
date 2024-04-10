#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	multiset<long long> use;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		use.insert(x);
		sum += x;
	}
	if (n == 1) {
		cout << "YES" << '\n';
		return;
	}
	multiset<long long> cur;
	cur.insert(sum);
	while (!cur.empty()) {
		auto x = *cur.rbegin();
		if (cur.size() > 2 * use.size() || x == 0) {
			cout << "NO" << '\n';
			return;
		}
		cur.erase(cur.find(x));
		auto lo = x / 2;
		auto hi = x - lo;
		auto bash = [&](long long z) {
			if (use.count(z)) {
				use.erase(use.find(z));
			} else {
				cur.insert(z);
			}
		};
		bash(lo);
		bash(hi);
	}
	if (!use.empty()) {
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
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