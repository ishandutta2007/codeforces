#include <iostream>
using namespace std;

int main() {
	int n, maxi = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		maxi = max(maxi, x);
	}
	cout << max(0, maxi - 25);
	return 0;
}