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
	int n;
	cin >> n;
	bool b = false;
	for (int i = 1; i <= n; i++) {
		if (lucky(i) && n % i == 0) {
			b = true;
		}
	}
	if (b)
		cout << "YES";
	else
		cout << "NO";
}