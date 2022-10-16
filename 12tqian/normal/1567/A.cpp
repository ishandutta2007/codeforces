#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == 'U') {
			t += 'D';
		} else if (s[i] == 'D') {
			t += 'U';
		} else if (s[i] == 'L') {
			++i;
			t += 'L';
			t += 'R';
		}
	}
	cout << t << '\n';
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