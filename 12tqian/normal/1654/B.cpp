#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	const int A = 26;
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int> last(A);
	for (int i = 0; i < n; ++i) {
		last[s[i] - 'a'] = i;
	}
	string ans = "";
	for (int i = 0; i < n; ++i) {
		if (last[s[i] - 'a'] == i) {
			ans = string(s.begin() + i, s.end());
			break;
		}
	}
	cout << ans << '\n';
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