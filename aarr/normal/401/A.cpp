#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, x, s = 0;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		s += y;
	}
	cout << (int) ceil((double) abs(s) / x);
	return 0;
}