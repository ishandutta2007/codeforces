#include <iostream>
using namespace std;

int main() {
	string s;
	bool b = false;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
			b = true;
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