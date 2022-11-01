#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		x += b - a;
		ans = max(ans, x);
	}
	cout << ans;
	return 0;
}