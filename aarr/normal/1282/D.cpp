#include <iostream>
using namespace std;

int main() {
	cout << "a" << endl << flush;
	int n, m;
	cin >> n;
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		cout << "b" << endl << flush;
		int k;
		cin >> k;
		if (k == 1) {
			cout << "ab" << endl << flush;
			int x;
			cin >> x;
			if (x != 0) {
				cout << "ba" << endl << flush;
			}
		}
		if (k == 2) {
			cout << "aa" << endl << flush;
		}
		return 0;
	}
	if (n == 300) {
		string t;
		for (int i = 0; i < 300; i++) {
			t += 'b';
		}
		cout << t << endl << flush;
	}
	string s;
	for (int i = 0; i <= n; i++) {
		s += 'a';
	}	
	cout << s << endl << flush;
	cin >> m;
	if (n < m) {
		string t;
		for (int i = 1; i <= n; i++) {
			t += 'b';
		}
		cout << t << endl << flush;
		return 0;
	}
	int x = m;
	for (int i = 0; i <= n; i++) {
		s[i] = 'b';
		cout << s << endl << flush;
		int y;
		cin >> y;
		if (y == 0) {
			return 0;
		}
		if (y >= x) {
			s[i] = 'a';
		}
		else {
			x = y;
		}
	}
	return 0;
}