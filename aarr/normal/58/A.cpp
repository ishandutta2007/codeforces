#include <iostream>
using namespace std;

string t = "hello";
int main() {
	string s;
	cin >> s;
	int x = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == t[x]) {
			x++;
		}
		if (x == 5) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}