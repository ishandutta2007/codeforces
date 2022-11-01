#include <iostream>
using namespace std;

int main() {
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	if (m > n)
		swap(n, m);
	m -= 2;
	for (int i = 0; i < k; i++) {
		ans += n + m;
		n -= 4;
		m -= 4;
	}
	ans *= 2;
	cout << ans;
	return 0;
}