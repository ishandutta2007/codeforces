#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b == c || a + c == b || b + c == a) {
		cout << "YES" << '\n';
	} else if (a % 2 == 0 && b == c) {
		cout << "YES" << '\n';
	} else if (b % 2 == 0 && a == c) {
		cout << "YES" << '\n';
	} else if (c % 2 == 0 && a == b) {
		cout << "YES" << '\n';		
	} else {
		cout << "NO" << '\n';
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