#include <iostream>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (n <= m) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << i * (n + j) << " ";
			}
			cout << "\n";
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << (i + m) * j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}