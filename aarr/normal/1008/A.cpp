#include <iostream>
#include <algorithm>
using namespace std;

bool vow(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

int main() {
	string s;
	cin >> s;
	bool b = true;
	s.push_back('b');
	for (int i = 0; i + 1 < s.size(); i++) {
		if (!vow(s[i]) && s[i] != 'n' && !vow(s[i + 1])) {
			b = false;
		}
	}
	if (b) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}