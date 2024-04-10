#include <iostream>
using namespace std;

int main() {
	string s, t;
	cin >> s;
	int i = 0;
	while (i < s.size()) {
		if (s[i] == '.') {
			t += '0';
			i++;
		}
		else {
			if (s[i + 1] == '.') {
				t += '1';
			}
			else {
				t += '2';
			}
			i += 2;
		}
	}
	cout << t;
	return 0;
}