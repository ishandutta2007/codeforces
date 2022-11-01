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
int main() {
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		string s;
		cin >> n >> s;
		int lt = 0;
		bool mark = false;
		for (int i = 0; i < s.size(); i++) {
			if (lt && (s[i] - '0') % 2 && !mark) {
				cout << lt << s[i] << endl;
				mark = true;
				break;
			}
			if ((s[i] - '0') % 2) {
				lt = s[i] - '0';
			}
		}
		if (!mark) {
			cout << -1 << endl;
		}
	}
}