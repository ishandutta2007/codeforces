#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>

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
map <string, string> mp;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s, t;
		cin >> s >> t;
		if (s.size() > t.size()) {
			mp[s] = t;
		}
		else {
			mp[s] = s;
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cout << mp[s] << " ";
	}
}