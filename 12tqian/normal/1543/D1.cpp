#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n, k;
	cin >> n >> k;
	int L = 0;
	int prod = 1;
	while (prod <= n) {
		prod *= k;
		++L;
	}
	++L;
	vector<array<int, 2>> delta(L, {1, 0});
	auto mod = [&](int x) {
		x %= k;
		if (x < 0) {
			x += k;
		}
		return x;
	};
	auto now = [&](int x) {
		int res = 0;
		int prod = 1;
		for (int i = 0; i < L; ++i) {
			int d = x % k;
			res += mod(delta[i][0] * d + delta[i][1]) * prod;
			prod *= k;
			x /= k;
		}
		return res;
	};
	auto query = [&](int x) {
		cout << x << endl;
		cin >> x;
		return x;
	};
	for (int i = 0; i < n; ++i) {
		int x = now(i);
		if (query(x)) {
			break;
		} 
		for (int j = 0; j < L; ++j) {
			delta[j][0] *= -1;
			delta[j][1] = mod(x - delta[j][1]);
			if (delta[j][1] > k) {
				delta[j][1] -= k;
			}
			x /= k;
		}
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