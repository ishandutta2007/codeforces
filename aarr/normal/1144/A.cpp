#include <iostream>
using namespace std;

const int N = 26;

int a[N];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		for (int i = 0; i < N; i++) {
			a[i] = 0;
		}
		for (int i = 0; i < s.size(); i++) {
			a[s[i] - 'a']++;
		}
		bool b = true;
		int x = -1, y = -1;
		for (int i = 0; i < N; i++) {
			if (a[i] > 1) {
				b = false;
			}
			if (a[i]) {
				if (x == -1) {
					x = i;
				}
				y = i;
			}
		}
		if (b && y - x + 1 == s.size()) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}