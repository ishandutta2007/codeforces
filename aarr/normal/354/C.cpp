#include <iostream>
using namespace std;


const int A = 1000 * 1000 + 5;

int ps[2 * A];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ps[x]++;
	}
	for (int i = 1; i < 2 * A; i++) {
		ps[i] += ps[i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		if (!ps[i - 1]) {
			ans = i;
		}
	}
	for (int i = k + 1; i < A; i++) {
		bool b = true;
		if (ps[i - 1]) {
			b = false;
		}
		for (int j = i; j < 2 * A; j += i) {
			if (ps[j - i + k] != ps[j - 1]) {
				b = false;
			}
		}
		if (b) {
			ans = i;
		}
	}
	cout << ans;
	return 0;
}