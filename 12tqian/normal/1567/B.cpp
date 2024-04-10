#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int a, b;
	cin >> a >> b;
	static vector<int> prefix{0};
	while ((int)prefix.size() < a) {
		prefix.push_back(prefix.back() ^ ((int)prefix.size()));
	}
	int sum = 0;
	if (a != 0) {
		sum = prefix[a - 1];
	}
	sum = sum ^ b;
	if (sum == 0) {
		cout << a << '\n';
	} else if (sum == a) {
		cout << a + 2 << '\n'; 
	} else {
		cout << a + 1 << '\n';
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