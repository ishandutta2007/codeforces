#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	string s;
	cin >> s;
	int n = s.size();
	deque<char> a;
	for (char c : s) {
		a.push_back(c);
	}
	for (int i = n - 1; i >= 0; --i) {
		if (a.front() - 'a' == i) {
			a.pop_front();
		} else if (a.back() - 'a' == i) {
			a.pop_back();
		} else {
			cout << "NO" << '\n';
			return;
		}
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