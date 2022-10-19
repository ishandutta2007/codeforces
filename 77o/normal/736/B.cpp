#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n == 2) {
		cout << "1\n";
		return 0;
	}
	if (n % 2 == 0) {
		cout << "2\n";
		return 0;
	}
	bool prime = true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	if (prime) {
		cout << "1\n";
	} else {
		bool prime = true;
		int m = n - 2;
		for (int i = 2; i * i <= m; i++) {
			if (m % i == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			cout << "2\n";
		} else {
			cout << "3\n";
		}
	}
	return 0;
}