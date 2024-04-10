#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int x = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '4' || s[i] == '7')
			x++;
	}
	if (x == 4 || x == 7) {
		cout << "YES";
	}
	else
		cout << "NO";
	return 0;
}