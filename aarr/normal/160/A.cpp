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
	int n, s = 0, x = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		x += a[i];
		if (x * 2 > s) {
			cout << n - i;
			return 0;
		}
	}
}