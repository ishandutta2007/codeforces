#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		int res, A, B, C;
		res = 1000000000;
		for(int a2 = 1; a2 <= a*2; ++a2)
			for (int b2 = a2; b2 <= b * 2; b2 += a2) {
				int c2;
				c2 = c / b2 * b2;
				if (c2 >= b2 && abs(c - c2) + abs(b - b2) + abs(a - a2) < res) {
					res = abs(c - c2) + abs(b - b2) + abs(a - a2);
					A = a2;
					B = b2;
					C = c2;
				}
				c2 = c / b2 * b2+b2;
				if (c2 >= b2 && abs(c - c2) + abs(b - b2) + abs(a - a2) < res) {
					res = abs(c - c2) + abs(b - b2) + abs(a - a2);
					A = a2;
					B = b2;
					C = c2;
				}
			}
		cout << res << endl;
		cout << A << " " << B << " " << C << endl;
	}
	return 0;
}