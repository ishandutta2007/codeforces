#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int k; 
	cin >> k;
	string s; 
	cin >> s;
	reverse(s.begin(), s.end());
	int n = 1 << k;
	vector<int> cnt(2 * n, 1);
	auto upd = [&](int i) -> int {
		cnt[i] = 0;
		if (s[i] != '0') {
			cnt[i] += cnt[2 * i + 1];
		}
		if (s[i] != '1') {
			cnt[i] += cnt[2 * i + 2];
		}
		return cnt[i];
	};
	for (int i = n - 2; i >= 0; --i) {
		upd(i);
	}
	int q;
	cin >> q;
	while (q--) {
		int p;
		char c;
		cin >> p >> c;
		p = n - p - 1;
		s[p] = c;
		while (p) {
			upd(p);
			p = (p - 1) >> 1;
		}
		cout << upd(0) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}