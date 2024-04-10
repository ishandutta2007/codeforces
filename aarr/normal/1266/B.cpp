#include <iostream>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long x;
		cin >> x;
		if (x % 14 < 7 && x % 14 != 0 && x > 14) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}