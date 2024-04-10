#include <bits/stdc++.h>

using namespace std;

int ntest, n;

string s;

int main() {
	cin >> ntest;
	while (ntest--) {
		long long k, x;
		cin >> k >> x;
		cout << x + (k - 1) * 9 << endl;
	}
	return 0;
}