#include <iostream>
#include <algorithm>
using namespace std;

int a[105];
int main() {
	int n, m, s = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int i;
	for (i = n - 1; i >= 0 && m > s; i--) {
		s += a[i];
	}
	cout << n - i - 1 << endl;
	return 0;
}