#include <iostream>
using namespace std;

int main() {
	int n, maxi = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		maxi = max(maxi, x + y);
	}
	cout << maxi;
	return 0;
}