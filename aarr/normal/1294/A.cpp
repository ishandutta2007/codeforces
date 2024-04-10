#include <iostream>
using namespace std;



int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		int y = max(max(a, b), c);
		int x = 3 * y - a - b - c;
		if ((a + b + c + n) % 3 == 0 && x <= n) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}