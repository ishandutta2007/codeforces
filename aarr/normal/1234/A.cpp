#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, s = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			s += x;
		}
		cout << (s - 1) / n + 1 << endl;
	}
	return 0;
}