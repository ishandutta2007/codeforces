#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool solve(string s, char a, char b, char c) {
	for (auto& z : s) {
		z = (z == 'A' ? a : (z == 'B' ? b : c));
	}
	int bal = 0;
	for (auto c : s) {
		if (c == '(') {
			bal++;
		}
		else {
			bal--;
		}
		if (bal < 0) {
			return false;
		}
	}
	return (bal == 0);
}

int main() {
	string s = "()";
	int t;
	cin >> t;
	while (t--) {
		string d;
		cin >> d;
		bool yep = false;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					yep |= solve(d, s[i], s[j], s[k]);
				}
			}
		}
		cout << (yep ? "YES\n" : "NO\n");
	}
}