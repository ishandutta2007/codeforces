#include <iostream>
using namespace std;

const int inf = 1000 * 1000 * 1000 + 7;

long long a[5];

int main() {
	cin >> a[1] >> a[2] >> a[3];
	cout << "First" << endl;
	cout << inf << endl;
	int x;
	cin >> x;
	if (!x) {
		return 0;
	}
	a[x] += inf;
	long long k = 3ll * a[x];
	for (int i = 1; i <= 3; i++) {
		k -= a[i];
	}
	cout << k << endl;
	int y;
	cin >> y;
	if (!y) {
		return 0;
	}
	a[y] += k;
	int z;
	for (int i = 1; i <= 3; i++) {
		if (i != x && i != y) {
			z = i;
		}
	}
	cout << a[x] - a[z] << endl;
	int zero;
	cin >> zero;
	return 0;
}