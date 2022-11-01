#include <iostream>
using namespace std;

int main() {
	int n, maxi, mini;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (i == 1) {
			maxi = x;
			mini = x;
		}
		maxi = max(maxi, x);
		mini = min(mini, x);
	}
	cout << maxi - mini + 1 - n << endl;
	return 0;
}