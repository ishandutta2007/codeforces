#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << k << " ";
			}
			else {
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}