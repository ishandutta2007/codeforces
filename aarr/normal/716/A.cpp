#include <iostream>
using namespace std;


int a[100 * 1000 + 5];
int main() {
	int n, c, ans = 0;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] > c)
			ans = 0;
		ans++;
	}
	cout << ans;
	return 0;
}