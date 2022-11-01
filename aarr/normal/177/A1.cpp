#include <iostream>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (i == n / 2 || j == n / 2 || i == j || i + j == n - 1)
				ans += x;
		}
	}
	cout << ans << endl;
	return 0;
}