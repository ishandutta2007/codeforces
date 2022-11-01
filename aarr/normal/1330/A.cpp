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
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, x, cnt = 0, ans = 0;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			int y;
			cin >> y;
			mark[y] = true;
		}
		for (int i = 1; i < N; i++) {
			if (mark[i]) {
				cnt++;
			}
			if (cnt >= i - x) {
				ans = i;
			}
		}
		for (int i = 0; i < N; i++) {
			mark[i] = false;
		}
		cout << ans << endl;
	}
}