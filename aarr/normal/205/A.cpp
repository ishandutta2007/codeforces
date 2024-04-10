#include <iostream>
#include <cmath>
using namespace std;

int a[100 * 1000 + 5];

int main() {
	int n, maxfor = 0, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < a[maxfor] || i == 0) {
			maxfor = i;
			cnt = 0;
		}
		if (a[i] == a[maxfor]) {
			cnt++;
		}
	}
	if (cnt > 1) {
		cout << "Still Rozdil";
	}
	else {
		cout << maxfor + 1;
	}
	return 0;
}