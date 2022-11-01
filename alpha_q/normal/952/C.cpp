#include <bits/stdc++.h>

using namespace std;

int n, a[100];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		if (abs(a[i] - a[i + 1]) >= 2) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}