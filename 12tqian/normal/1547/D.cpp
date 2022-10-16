#include <bits/stdc++.h>

using namespace std;

const int L = 30;
const int INF = 2e9;

bool bit(int x, int j) {
	return (1 << j) & x;
}

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	vector<int> ans(n);
	for (int i = 1; i < n; ++i) {
		int a = x[i - 1] ^ ans[i - 1];
		for (int j = L - 1; j >= 0; --j) {
			bool b1 = bit(a, j);
			bool b2 = bit(x[i], j);
			if (b1 && b2) {

			} else if (b1) {
				ans[i] += (1 << j);
			} else if (b2) {

			} else {
				
			}
		}
	}
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
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