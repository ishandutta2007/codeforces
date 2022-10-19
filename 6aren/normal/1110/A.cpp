#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
	int b, k, sum = 0;
	cin >> b >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		sum += (a[i] % 2);
	}
	if (b % 2 == 0) {
		if (a[k] % 2 == 0) {
			cout << "even";
		} else {
			cout << "odd";
		}
	} else {
		if (sum % 2 == 0) {
			cout << "even";
		} else {
			cout << "odd";
		}
	}
	return 0;
}