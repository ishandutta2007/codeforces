#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	string s; 
	cin >> s;
	int n = s.size();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			a[i] = -1;
		} else {
			int x = s[i] - '0';
			x ^= (i % 2);
			a[i] = x;
		}
	}
	vector<vector<int>> pre(2, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			pre[j][i] = (i ? pre[j][i - 1] : 0) + (a[i] == j);
		}
	}
	auto get = [&](int t, int l, int r) -> int {
		return pre[t][r] - (l ? pre[t][l - 1] : 0);
	};
	auto get_far = [&](int idx, int t) -> int {
		t ^= 1;
		int lo = idx;
		int hi = n - 1;
		while (hi - lo > 1) {
			int mid = (lo + hi) >> 1;
			if (get(t, idx, mid) == 0) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}
		if (get(t, idx, hi) == 0) {
			return hi - idx + 1;
		} else {
			return lo - idx + 1;
		}
	};
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) {
			ans += get_far(i, 0);
			ans += get_far(i, 1);
		} else {
			ans += get_far(i, a[i]);
		}
	}
	int i1 = 0;
	int i2 = 0;
	while (i1 != n) {
		while (i2 < n - 1 && a[i1] == a[i2 + 1]) {
			++i2;
		}
		if (a[i1] == -1) {
			ans -= 1LL * (i2 - i1 + 1) * (i2 - i1 + 2) / 2;
		}
		i1 = ++i2;
	}
	cout << ans << '\n';
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