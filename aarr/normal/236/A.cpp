#include <iostream>
using namespace std;

bool b[30];
int main() {
	string s;
	cin >> s;
	for (int i = 0 ; i < s.size(); i++) {
		b[s[i] - 'a'] = true;
	}
	bool ans = false;
	for (int i = 0; i < 26; i++) {
		ans ^= b[i];
	}
	if (ans) {
		cout << "IGNORE HIM!";
	}
	else
		cout << "CHAT WITH HER!";
	return 0;
}