#include <iostream>
using namespace std;

int digsum(int n) {
	int ans = 0;
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	while (digsum(n) % 4 != 0) {
		n++;
	}
	cout << n;
	return 0;
}