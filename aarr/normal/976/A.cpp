#include <iostream>
using namespace std;

int main() {
	int n, x = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			x++;
		}
	} 
	if (s.size() == 1 && x == 1) {
		cout << 0;
	}
	else {
		cout << 1;
		for (int i = 0; i < x; i++) {
			cout << 0;
		}
	}
	return 0;
}