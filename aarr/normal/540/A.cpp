#include <iostream>
using namespace std;



int main() {
	int n, ans = 0;
	string s;
	string t;
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++) {
		int x = s[i] - t[i];
		x = abs(x);
		ans += min(x, 10 - x);
	}
	cout << ans;
	return 0;
}