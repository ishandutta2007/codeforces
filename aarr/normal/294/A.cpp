#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int a[105];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	for (int j = 0; j < q; j++) {
		int x, y;
		cin >> x >> y;
		a[x - 1] += y - 1;
		a[x + 1] += a[x] - y;
		a[x] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}