#include <iostream>
#include <algorithm>
using namespace std;

int a[300 * 1000 + 5];
int main() {
	int n;
	long long s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	sort(a, a + n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << s - a[n - x] << endl;
	}
	return 0;
}