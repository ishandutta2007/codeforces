#include <iostream>
using namespace std;

int a[105][10];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a[i][0];
		cin >> a[i][1];
		cin >> a[i][2];
		cin >> a[i][3];
		cin >> a[i][4];
		if (a[i][3] < a[i][4]) {
			swap(a[i][3], a[i][4]);
			swap(a[i][1], a[i][2]);
		}
		if (a[i][0] > a[i][1] * 2) {
			int ans = a[i][1] * a[i][3];
			a[i][0] -= 2 * a[i][1];
			ans += min(a[i][2], a[i][0] / 2) * a[i][4];
			cout << ans << endl;
		}
		else {
			cout << a[i][0] / 2 * a[i][3] << endl;
		}
	}
	return 0;
}