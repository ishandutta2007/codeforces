#include <iostream>
using namespace std;

int a[5];
int main() {
	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	for (auto c : s) {
		ans += a[c - '0'];
	}
	cout << ans << endl;
	return 0;
}