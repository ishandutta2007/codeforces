#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long n;
		cin >> n;
		int ans = 0;
		while (n % 2 == 0) {
			ans++;
			n /= 2;
		}
		while (n % 3 == 0) {
			ans += 2;
			n /= 3;
		}
		while (n % 5 == 0) {
			ans += 3;
			n /= 5;
		}
		if (n > 1)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}