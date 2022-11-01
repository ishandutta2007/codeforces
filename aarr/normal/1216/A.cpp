#include <iostream>
using namespace std;

int main() {
	int n, ans = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n / 2; i++) {
		if (s[i * 2] == s[i * 2 + 1]) {
			if (s[i * 2] == 'a') {
				s[i * 2] = 'b';
			}
			else {
				s[i * 2] = 'a';
			}
			ans++;
		}
	}
	cout << ans << endl << s;
	return 0;
}