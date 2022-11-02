#include <iostream>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt += x;
		if (!x) {
			ans += cnt;
		}
	}
	cout << ans;
	return 0;
}