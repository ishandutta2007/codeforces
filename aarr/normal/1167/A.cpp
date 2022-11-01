#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool b = false;
		for (int i = 0; i < (int) s.size() - 10; i++) {
			if (s[i] == '8') {
				b = true;
			}
		}
		cout << (b? "YES" : "NO") << endl;
	}
	return 0;
}