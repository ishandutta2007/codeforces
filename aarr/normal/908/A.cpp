#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == '1' || c == '3' || c == '5' || c == '7' || c == '9') {
			ans++;
		}
	}
	cout << ans;
	return 0;
}