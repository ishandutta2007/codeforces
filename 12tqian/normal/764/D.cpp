#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << "YES" << '\n';
	for (int i = 0; i < n; ++i) {
		int xl, yl, xr, yr;
		cin >> xl >> yl >> xr >> yr;
		xl = (xl % 2 + 2) % 2;
		yl = (yl % 2 + 2) % 2;
		cout << xl * 2 + yl + 1 << '\n';
	}
	return 0;
}