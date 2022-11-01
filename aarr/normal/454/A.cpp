#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (abs(i - n / 2 - 1) < min(j, n - j + 1)) {
				cout << 'D';
			}
			else
				cout << '*';
		}
		cout << endl;
	}
	return 0;
}