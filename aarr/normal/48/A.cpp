#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


const int N = 2005;

int a[N];



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
int main() {
	string a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << '?';
		return 0;
	}
	if (a != b && b != c && a != c) {
		cout << '?';
	}
	else {
		if (a == c) {
			if ((b.size() == 4 && a.size() == 8) || (b.size() == 8 && a.size() == 5) || (b.size() == 5 && a.size() == 4)) {
				cout << 'M';
			}
			else {
				cout << '?';
			}
		}
		if (a == b) {
			if ((c.size() == 4 && a.size() == 8) || (c.size() == 8 && a.size() == 5) || (c.size() == 5 && a.size() == 4)) {
				cout << 'S';
			}
			else {
				cout << '?';
			}		
		}
		if (b == c) {
			if ((a.size() == 4 && b.size() == 8) || (a.size() == 8 && b.size() == 5) || (a.size() == 5 && b.size() == 4)) {
				cout << 'F';
			}
			else {
				cout << '?';
			}			
		}
	}
}