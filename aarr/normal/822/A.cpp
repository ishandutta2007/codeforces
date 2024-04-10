#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	long long ans = 1;
	for (int i = 1; i <= min(x, y); i++) {
		ans *= i;
	}
	cout << ans;
	return 0;
}