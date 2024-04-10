#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;
	while (ntest--) {
		int n;
		cin >> n;
		if (n == 2) {
			cout << 2 << '\n';
			cout << 1 << ' ' << 2 << '\n';
			continue;
		}
		cout << 2 << '\n';
		cout << n - 2 << ' ' << n << '\n';
		cout << n - 1 << ' ' << n - 1 << '\n';
		for (int i = n - 3; i >= 1; i--) {
			cout << i << ' ' << i + 2 << '\n';
		}
	}

	return 0;
}