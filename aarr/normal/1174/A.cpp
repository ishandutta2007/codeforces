#include <iostream>
#include <algorithm>
using namespace std;

int a[2019];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	sort(a, a + 2 * n);
	int s = 0, p = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	for (int i = n; i < 2 * n; i++) {
		p += a[i];
	}
	if (s == p)
		cout << -1;
	else {
		for (int i = 0; i < 2 * n; i++) {
			cout << a[i] << " ";
		}
	}
	return 0;
}