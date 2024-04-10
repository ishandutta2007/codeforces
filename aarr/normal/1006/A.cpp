#include <iostream>
using namespace std;

const int N = 1005;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 2 == 0)
			x--;
		cout << x << " ";
	}
	return 0;
}