#include <iostream>
using namespace std;

bool mark[15];

bool f(int n) {
	for (int i = 0; i < 10; i++) {
		mark[i] = false;
	}
	while (n > 0) {
		if (mark[n % 10]) {
			return false;
		}
		mark[n % 10] = true;
		n /= 10;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	n++;
	while (!f(n)) {
		n++;
	}
	cout << n;
	return 0;
}