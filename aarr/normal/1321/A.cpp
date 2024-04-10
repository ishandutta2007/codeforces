#include <iostream>
#include <cmath>
using namespace std;

int a[105], b[105];

int main() {
	int n, x = 0, y = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (a[i] && !b[i]) {
			x++;
		}
		if (b[i] && !a[i]) {
			y++;
		}
	}
	if (x == 0)
		cout << -1;
	else
		cout << y / x + 1;
	return 0;
}