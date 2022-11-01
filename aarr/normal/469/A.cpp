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
int main() {
	int n;
	cin >> n;
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		int a;
		cin >> a;
		b[a] = true;
	}
	int y;
	cin >> y;
	for (int i = 0; i < y; i++) {
		int a;
		cin >> a;
		b[a] = true;
	}
	bool ans = true;
	for (int i = 1; i <= n; i++) {
		ans &= b[i];
	}
	if (ans) {
		cout << "I become the guy.";
	}
	else {
		cout << "Oh, my keyboard!";
	}
}