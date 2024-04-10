#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'Q') {
			x++;
			z += y;
		}
		if (s[i] == 'A') {
			y += x;
		}
	}
	cout << z << endl;
	return 0;
}