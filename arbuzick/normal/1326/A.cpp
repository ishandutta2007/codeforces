#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		if (n == 1)
			cout << -1 << endl;
		else if ((n - 1) % 3 == 0) {
			for (int j = 0; j < n - 2; ++j)
				cout << 2;
			cout << 33 << endl;
		}
		else {
			for (int j = 0; j < n - 1; ++j)
				cout << 2;
			cout << 3 << endl;
		}
	}
	return 0;
}