#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
	string s;
	cin >> s;
	if (s.size() % 2 == 1) {
		cout << s[s.size() / 2];
		for (int i = 1; i <= s.size() / 2; i++) {
			cout << s[s.size() / 2 + i];
			cout << s[s.size() / 2 - i];
		}
	}
	else {
		for (int i = 0; i < s.size() / 2; i++) {
			cout << s[s.size() / 2 - i - 1];
			cout << s[s.size() / 2 + i];
		}		
	}
	return 0;
}