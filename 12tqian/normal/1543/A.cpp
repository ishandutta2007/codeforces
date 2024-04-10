#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	long long a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0 << ' ' << 0 << '\n';
	} else {
		if (a > b) {
			swap(a, b);
		}
		long long g = abs(a - b);
		cout << g << ' ' << min(a % g, g - a % g)  << '\n';;
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