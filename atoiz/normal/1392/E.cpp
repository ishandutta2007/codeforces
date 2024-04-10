#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j && (i == 1 || i == n)) cout << 0 << ' ';
			else cout << ((i & 1ll) << (i + j - 3)) << ' ';
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while (q--) {
		int64_t k;
		cin >> k;

		int x = 1, y = 1;
		cout << x << ' ' << y << endl;
		for (int d = 3; d <= 2 * n - 1; ++d) {
			if ((x & 1) == ((k >> (d - 3)) & 1)) ++y;
			else ++x;
			cout << x << ' ' << y << endl;
		}
		cout << n << ' ' << n << endl;
	}
}