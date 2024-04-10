#include <iostream>
using namespace std;

int main() {
	int n, x = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (t == -1 && x == 0) {
			ans++;
		}
		else {
			x += t;
		}
	} 
	cout << ans << endl;
	return 0;
}