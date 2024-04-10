#include <iostream>
#include <cmath>
using namespace std;

int a[105];
int main() {
	int n, s = 0, x = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		x = max(x, y);
		s += y;
	}
	x = max(x, (int) ceil((double) (2 * s + 1) / n));
	cout << x;
	return 0;
}