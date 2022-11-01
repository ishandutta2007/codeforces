#include <iostream>
using namespace std;


int main() {
	int n, a, x, b, y;
	cin >> n;
	cin >> a;
	cin >> x;
	cin >> b;
	cin >> y;
	for (int i = 0; i < n; i++) {
		a++;
		if (a > n)
			a = 1;
		b--;
		if (b < 1)
			b = n;
		if (a == b) {
			cout << "YES";
			break;
		}
		if (a == x || b == y) {
			cout << "NO";
			break;
		}
			
	}
	return 0;
}