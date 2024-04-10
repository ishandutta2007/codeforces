#include <iostream>
using namespace std;

int main() {
	int n, x = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A')
			x++;
		else
			x--;
	}
	if (x > 0) {
		cout << "Anton" << endl;
	}
	if (x == 0) {
		cout << "Friendship" << endl;
	}
	if (x < 0) {
		cout << "Danik" << endl;
	}
	return 0;
}