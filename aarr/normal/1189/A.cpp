#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 0, y = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			x++;
		else
			y++;
	}
	if (x != y) {
		cout << 1 << endl << s << endl;
	}
	else {
		cout << 2 << endl;
		cout << s[0] << " ";
		for (int i = 1; i < s.size(); i++) {
			cout << s[i];
		}
	}
	return 0;
}