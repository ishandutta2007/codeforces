#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n *= 2;
	bool b = false;
	for (int i = 1; i <= n; i++) {
		if (i * (i + 1) == n) {
			b = true;
		}
	}
	if (b) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}