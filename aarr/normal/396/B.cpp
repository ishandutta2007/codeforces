#include <iostream>
#include <map>
using namespace std;

map <int, bool> mp;

bool prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
long long bmm(long long x, long long y) {
	if (y == 0)
		return x;
	return bmm(y, x % y);
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		long long j = n, k = n + 1;
		for (j; !prime(j); j--) {
			
		}
		for (k; !prime(k); k++) {
			
		}
		long long x = j * k - 2 * k + 2 * n - 2 * j + 2, y = 2 * j * k;
		long long z = bmm(x, y);
		cout << x / z << "/" << y / z << endl;
	}
	return 0;
}