#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long n;
	int k;
	cin >> n >> k;
	int c2 = 0, c5  = 0;
	int m = n;
	while(m % 2 == 0) {
		m /= 2;
		c2++;
	}
	while(m % 5 == 0) {
		m /= 5;
		c5++;
	}
	while(c2 < k) {
		n *= 2;
		c2++;
	}
	while(c5 < k) {
		n *= 5;
		c5++;
	}
	cout << n;
}