#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n;
		cin >> n;
		if (n % 3 == 0)
			cout << n / 3 << ' ' << 0 << ' ' << 0 << '\n';
		else if (n % 3 == 1) {
			if (n < 7)
				cout << -1 << '\n';
			else 
				cout << (n - 7) / 3 << ' ' << 0 << ' ' << 1 << '\n';
		} else {
			if (n < 5)
				cout << -1 << '\n';
			else cout << (n - 5) / 3 << ' ' << 1 << ' ' << 0 << '\n';
		}
	}

	return 0;
}