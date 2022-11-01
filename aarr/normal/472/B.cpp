#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2005;

int a[N];
int main() {
	int n, k, s = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = -a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i += k) {
		s += 2 * (a[i] + 1);
	}
	cout << -s << endl;
	return 0;
}