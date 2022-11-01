#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n--;
	long long ans = 1;
	for (int i = n + 1; i <= 2 * n; i++) {
		ans *= i;
	}
	for (int i = 1; i <= n; i++) {
		ans /= i;
	}
	cout << ans;
}