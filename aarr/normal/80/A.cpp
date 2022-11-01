#include <iostream>
using namespace std;

bool f(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	bool b = true;
	for (int i = n + 1; i < m; i++) {
		if (f(i)) {
			b = false;
		}
	}
	if (!f(m)) {
		b = false;
	}
	if (b) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}