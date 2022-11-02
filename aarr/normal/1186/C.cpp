#include <iostream>
using namespace std;

int main() {
	string s, t;
	cin >> s;
	cin >> t;
	int x = 0, y = 0, ans = 0;
	for (int i = 0; i < t.size(); i++) {
		y += (t[i] - '0');
		x += (s[i] - '0');
	}
	if (x % 2 == y % 2)
		ans++;
	for (int i = t.size(); i < s.size(); i++) {
		x += (s[i] - '0');
		x -= (s[i - t.size()] - '0');
		if (x % 2 == y % 2) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}