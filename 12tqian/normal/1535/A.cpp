#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	vector<int> s(4);
	for (int i = 0; i < 4; ++i) {
		cin >> s[i];
	}
	if (max(s[0], s[1]) <= min(s[2], s[3])) {
		cout << "NO" << '\n';
	} else if (min(s[0], s[1]) >= max(s[2], s[3])) {
		cout << "NO" << '\n'; 
	} else {
		cout << "YES" << '\n';
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