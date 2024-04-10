#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


const int N = 100 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;

int a[N];
bool mark[N];


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
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double x = max(3 * a / 10, a - a / 250 * c);
	double y = max(3 * b / 10, b - b / 250 * d);
	if (abs(x - y) <= 0.000001) {
		cout << "Tie";
		return 0;
	}
	if (x > y) {
		cout << "Misha";
	}
	else {
		cout << "Vasya";
	}
}