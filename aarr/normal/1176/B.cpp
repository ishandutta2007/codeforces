#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n, a = 0, b = 0, c = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x % 3 == 0)
				a++;
			if (x % 3 == 1)
				b++;
			if (x % 3 == 2)
				c++;
		}
		if (b > c)
			swap(b, c);
		a += b;
		c -= b;
		a += (c / 3);
		cout << a << endl;
	}
	return 0;
}