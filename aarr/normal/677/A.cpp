#include <iostream>
using namespace std;

int main() {
	int n, h, ans = 0;
	cin >> n;
	cin >> h;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > h)
			ans++;
	}
	cout << ans + n << endl;
	return 0;
}