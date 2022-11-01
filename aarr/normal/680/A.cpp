#include <iostream>
#include <algorithm>
using namespace std;

int a[105];

int main() {
	int s = 0;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		a[x]++;
		s += x;
	}
	int ans = s;
	for (int i = 0; i <= 100; i++) {
		if (a[i] > 1) {
			ans = min(ans, s - min(a[i], 3) * i);
		}
	}
	cout << ans;
	return 0;
}