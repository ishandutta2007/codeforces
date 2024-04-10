#include <iostream>
using namespace std;


const int N = 100 * 1000 + 5;

int main() {
	int n, m;
	cin >> n >> m;
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 2)
			a++;
		else
			b++;
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x % 2)
			c++;
		else
			d++;
	}
	cout << min(a, d) + min(b, c);
	return 0;
}