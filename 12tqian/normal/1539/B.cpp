#include <bits/stdc++.h>

using namespace std;

const int A = 26; 

void solve_case(int tc = 0) {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<vector<int>> p(A, vector<int>(n));
	for (int c = 0; c < A; ++c) {
		for (int i = 0; i < n; ++i) {
			p[c][i] = (i ? p[c][i - 1] : 0) + (s[i] - 'a' == c);
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		int ans = 0;
		for (int i = 0; i < A; ++i) {
			int amt = p[i][r] - (l ? p[i][l - 1] : 0);
			ans += amt * (i + 1);
		}
		cout << ans << '\n';
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