#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	string s;
	cin >> s;
	vector<int> cnt(3);
	for (char c : s) {
		++cnt[c - 'A'];
	}
	cout << (cnt[1] == cnt[0] + cnt[2] ? "YES" : "NO") << '\n';
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