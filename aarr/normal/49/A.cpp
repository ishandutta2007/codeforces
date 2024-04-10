#include <iostream>
using namespace std;

int main() {
	bool b = false;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
			if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
				b = true;
			}
			else {
				b = false;
			}
		//	cout << i << endl;
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