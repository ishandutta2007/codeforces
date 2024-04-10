#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;


const int N = 100 * 1000 + 5;

bool b[N];



int get(int x, int y) {
	return (x >> y) & 1;
}
bool pal(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}
bool lucky(int x) {
	while (x) {
		if (x % 10 != 7 && x % 10 != 4) {
			return false;
		}
		x /= 10;
	}
	return true;
}
int bmm(int x, int y) {
	if (y == 0)
		return x;
	return bmm(y, x % y);
}
int main() {
	string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
	char c;
	string t;
	cin >> c >> t;
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == t[i]) {
				if (c == 'R') {
					cout << s[j - 1];
				}
				else {
					cout << s[j + 1];
				}
			}
		}
	}
}