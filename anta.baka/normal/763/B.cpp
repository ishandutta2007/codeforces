#include <iostream>
using namespace std;
int n, x, y;
main() {
	cin >> n; cout << "YES\n";
	while(n--) {
		cin >> x >> y >> x >> y;
		cout << 2 * (x & 1) + (y & 1) + 1 << '\n';
	}
}