#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;	
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		int x = abs(a - b), ans = 0;
		ans = x / 5;
		x %= 5;
		ans += x / 2;
		x %= 2;
		ans += x;
		cout << ans << endl;
	}
	return 0;
}