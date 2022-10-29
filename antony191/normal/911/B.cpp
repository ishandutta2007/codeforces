#include <iostream>


using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int k = 1;
	while (k <= a && k <= b) {
		int x = a / k, y = b / k;
		if (x + y < n)
			break;
		++k;
	}
	cout << k - 1;
	return 0;
}