#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int x = 0, ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int y = s[i] - 'a';
		ans += min(max(x, y) - min(x, y), min(x, y) - max(x, y) + 26);
		x = y;
	}
	cout << ans;
	return 0;
}