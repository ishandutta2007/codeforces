#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n << " ";
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			cout << n << " ";
		}
	}
	if (n > 1) {
		cout << 1 << " ";
	}
	return 0;
}