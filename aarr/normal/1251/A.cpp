#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


const int N = 200 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;

int a[N];
int b[N];
bool mark[N];
map <int, int> mp;


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
bool vow(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		string s;
		cin >> s;
		s += 'A';
		int lt = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[i - 1]) {
				if ((i - lt) % 2) {
					mark[s[i - 1] - 'a'] = true;
				}
				lt = i;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (mark[i]) {
				cout << (char) ('a' + i);
				mark[i] = false;
			}
		}
		cout << endl;
	}
}